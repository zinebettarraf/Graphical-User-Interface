#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ei_types.h"
#include "ei_utils.h"
#include "ei_draw.h"
#include "hw_interface.h"
#include "ei_draw_suite.h"
#include "ei_drawpolygon.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define POS(x) (((x)>0) ? 1 : -1)

/**
 * \brief	Converts the red, green, blue and alpha components of a color into a 32 bits integer
 * 		than can be written directly in the memory returned by \ref hw_surface_get_buffer.
 * 		The surface parameter provides the channel order.
*/

uint32_t		ei_map_rgba		(ei_surface_t surface, ei_color_t color)
{
    int ir=0,ig=0,ib=0,ia=-1;
    hw_surface_get_channel_indices( surface, &ir, &ig, &ib,  &ia);
    uint32_t pixel_encode;
    uint8_t* ptr=&pixel_encode;
    ptr[ir]=color.red;
    ptr[ig]=color.green;
    ptr[ib]=color.blue;
    if ( ia != -1 ) ptr[ia]=color.alpha;
    else ptr[ia]=0;
    return  pixel_encode;
}
/**
*La fonction principale utilisée par ei_draw_polyline.
* ELle est utilisée pour tracer un seul segment.
**/

void       ei_draw_line_clipping (ei_surface_t			surface,
                                  ei_linked_point_t*	first_point,
                                  ei_linked_point_t*	second_point,
                                  uint32_t			color,
                                  const ei_rect_t*		clipper,
                                  uint32_t *	pixel_ptr)
{
    int deltax = (second_point->point).x - (first_point->point).x;
    int deltay = (second_point->point).y - (first_point->point).y;
    ei_point_t point;
    ei_linked_point_t* newpoint = malloc(sizeof(ei_linked_point_t));
    if(deltax == 0 && deltay == 0)
    {

        color_clipped(surface, first_point, color, clipper, pixel_ptr);

    }
    if(deltax == 0)
    {
        for (int i = MIN((first_point->point).y,(second_point->point).y); i<= MAX((first_point->point).y,(second_point->point).y); i++)
        {
            point.x = (first_point->point).x;
            point.y = i;
            newpoint->point = point;
            color_clipped(surface, newpoint, color, clipper, pixel_ptr);
        }
    }
    else if(deltay == 0)
    {
        for (int i = MIN((first_point->point).x,(second_point->point).x); i<= MAX((first_point->point).x,(second_point->point).x); i++)
        {
            point.x = i;
            point.y = (first_point->point).y;
            newpoint->point = point;
            color_clipped(surface, newpoint, color, clipper, pixel_ptr);
        }
    }
    else if(abs(deltax)>abs(deltay))
    {
        int E = 0;
        int x1 = (first_point->point).x;
        int y1 = (first_point->point).y;
        while(x1<=MAX((first_point->point).x,(second_point->point).x) && x1>=MIN((first_point->point).x,(second_point->point).x))
        {
            point.x = x1;
            point.y = y1;
            newpoint->point = point;
            color_clipped(surface, newpoint, color, clipper, pixel_ptr);
            x1+=POS(deltax);
            E+=abs(deltay);
            if ( 2*E > deltax)
            {
                y1+=POS(deltay);
                E-=abs(deltax);
            }
        }
    }
    else if(abs(deltay)>=abs(deltax))
    {
        int E = 0;
        int x1 = (first_point->point).x;
        int y1 = (first_point->point).y;
        while(y1<=MAX((first_point->point).y,(second_point->point).y) && y1>=MIN((first_point->point).y,(second_point->point).y))
        {
            point.x = x1;
            point.y = y1;
            newpoint->point = point;
            color_clipped(surface, newpoint, color, clipper, pixel_ptr);
            y1+=POS(deltay);
            E+=abs(deltax);
            if ( 2*E > deltay)
            {
                x1+=POS(deltax);
                E-=abs(deltay);
            }

        }
    }
}

/**
 * \brief	Draws a line that can be made of many line segments.
 */
void			ei_draw_polyline	(ei_surface_t			surface,
						 const ei_linked_point_t*	first_point,
						 ei_color_t			color,
						 const ei_rect_t*		clipper)
{
        ei_linked_point_t*	pt =  (ei_linked_point_t*)first_point;
    uint32_t *    pixel_ptr = (uint32_t*)hw_surface_get_buffer(surface);
    uint32_t  colorf = ei_map_rgba(surface, color);
    if(pt==NULL){return;}
    ei_linked_point_t* pt_suiv = pt->next;
    while(pt->next != NULL)
    {
        ei_linked_point_t* second_point = pt->next;
        ei_draw_line_clipping(surface, pt, pt->next, colorf, clipper, pixel_ptr);
        pt=pt->next;
    }
}


/**
 * \brief	Fills the surface with the specified color.
 */
void			ei_fill			(ei_surface_t		surface,
                                    const ei_color_t*	color,
                                    const ei_rect_t*	clipper)
{
  uint32_t finalcolor = ei_map_rgba(surface, *color);
  uint32_t * pixel_ptr = (uint32_t*) hw_surface_get_buffer(surface);
  ei_size_t windowsize = hw_surface_get_size(surface);
  if (clipper){
    // Dans le cas ou un clipper est fourni, on ne colorie que les pixels qui y sont limités
    int a = clipper->top_left.x;
    int b = clipper->top_left.y;
    uint32_t *init;
    init = pixel_ptr + a + b*windowsize.width;
    for (int i = 0; i < (clipper->size.height); i++){
        for (int j = 0; j < (clipper->size.width); j++){
            *init++ = finalcolor;
        }
        init += windowsize.width - clipper->size.width;
    }
  }
  else{
    //On colorie toute la surface donnée
    for (int i = 0; i < (windowsize.width * windowsize.height); i++) {
        *pixel_ptr++ = finalcolor;
    }
  }
}


/**
 * \brief	Draws a filled polygon.
 */


void			ei_draw_polygon		(ei_surface_t			surface, const ei_linked_point_t*	first_point,
                                        ei_color_t			color,
                                        const ei_rect_t*		clipper) {


    /* bornes de l'algo*/
    int scanline_max = 0;
    int scanline_min = hw_surface_get_size(surface).height;
    ei_linked_point_t* point_par = (ei_linked_point_t*)first_point;
    while (point_par != NULL){
        if (point_par->point.y < scanline_min) scanline_min = point_par->point.y;
        else if (point_par->point.y > scanline_max) scanline_max = point_par->point.y;
        point_par = point_par->next;
    }
    /* initialiser TC*/
    int len = scanline_max - scanline_min + 1;
    ei_edge_t** TC= malloc(len*sizeof(ei_edge_t*));
    for (uint32_t i = 0; i < len; i++) TC[i] = NULL;
    /* remplir TC */
    ei_linked_point_t *ptr_point =( ei_linked_point_t*)first_point;
    ei_linked_point_t *second_point = first_point->next;
    while (second_point != NULL){
        if (second_point->point.y != ptr_point->point.y) // eviter les horizontales
            ajout_edge(&TC,second_point->point,ptr_point->point,scanline_min);
        ptr_point = second_point;
        second_point = ptr_point->next;
    }
    ajout_edge(&TC,first_point->point,ptr_point->point,scanline_min); // lier le dernier point au premier
    /* initialiser TCA */
    ei_edge_t* TCA= malloc(sizeof (ei_edge_t*));
    TCA=NULL;
    /* initialiser la scanline courante : elle est initialisée par  la première scanline qui intersecte le polygone*/
    int* scanline_courante= malloc(sizeof(int));
    *scanline_courante=scanline_min;
    /* debut de l'algo*/
    while (*scanline_courante != scanline_max + 1){  // condition d'arret de l'algo <=> canline d'arret est la scanline_max+1
        /*Déplacer les côtés de TC(y) dans TCA*/
        if (TC[*scanline_courante - scanline_min] != NULL){
            if (TCA == NULL) TCA = TC[*scanline_courante - scanline_min];
            else{
                ei_edge_t* edge_par=TCA;
                while (edge_par->next_edge!=NULL) edge_par=edge_par->next_edge;
                edge_par->next_edge = TC[*scanline_courante - scanline_min];
            }
        }
        /*Supprimer de TCA les côtés tels que ymax=y */
        delete_edges_TCA(&TCA, *scanline_courante);
        /*trier TCA par abscisse croissant des intersection de côté avec la scanline*/
        Merge_sort_list(&TCA);
        /*Modifier les pixels de l’image sur la scanline*/
        colorier_scanline(surface,&TCA,*scanline_courante,color,clipper);
        /*incrémenter y*/
        (*scanline_courante)++;
        /*Mettre à jour les abscisses d’intersections des côtés de TCA avec la nouvelle scanline*/
        if (TCA != NULL){   // on ne fait la mise à jour que si TCA est non NULL
            ei_edge_t* edge_update = TCA;
            while (edge_update != NULL){
                edge_update->x_ymin = intersection_scanline(edge_update->x_ymin, *scanline_courante - 1, edge_update->delta_x,edge_update->delta_y,  &(edge_update->E));
                edge_update = edge_update->next_edge;
            }
        }
    }
    free(TC); // le free de chaque cellule edge est fait lors de l'étape de suppression de l'algo il reste seulement le free du tableau TC
    free(scanline_courante); free(TCA); // ces deux allocations memoires etaient juste pour faire des appels à des fonctions dans le but de factoriser la fontion principal
}




/**
 * \brief	Draws text by calling \ref hw_text_create_surface.
 */

void			ei_draw_text		(ei_surface_t		surface,
                                     const ei_point_t*	where,
                                     const char*		text,
                                     ei_font_t		font,
                                     ei_color_t		color,
                                     const ei_rect_t*	clipper)
{

    ei_surface_t  surface_texte = hw_text_create_surface(text, font, color);
    ei_size_t size_text = hw_surface_get_size(surface_texte);
    ei_rect_t rectangle_dst;
    rectangle_dst.top_left = *where;
    rectangle_dst.size = size_text;
    ei_rect_t* rectangle_src = NULL;


    /*
     On ajuste ce rectangle du texte dans le cas de clipper
    */

    if (clipper){
        int x = rectangle_dst.top_left.x ; int y = rectangle_dst.top_left.y ;
        int a = clipper->top_left.x; int b = clipper->top_left.y;
        rectangle_src = malloc(sizeof(ei_rect_t));
        rectangle_src->top_left = ei_point(0, 0);
        rectangle_src->size = size_text;
        bool flux_haut = y < b; bool flux_bas = (y+size_text.height) > (b+clipper->size.height);
        bool flux_gauche = x<a; bool flux_droite = (x+size_text.width) > (a + clipper->size.width);
        if (flux_haut){
            if ((y+size_text.height) < b){
                return;
            }
            else{
                rectangle_dst.top_left.y = b;
                rectangle_src->top_left.y += b-y;
                //modifier la taille!!
                rectangle_dst.size.height += y-b;
                rectangle_src->size.height += y-b;
            }
        }
        if (flux_bas){
            if (y > b + clipper->size.height){
                return;
            }
            else{
                rectangle_dst.size.height = b + clipper->size.height - y;
                rectangle_src->size.height = b + clipper->size.height - y;
            }
        }
        if (flux_gauche){
            if ((x+size_text.width) < a){
                return ;
            }
            else{
                rectangle_dst.top_left.x = a;
                rectangle_src->top_left.x += a-x;
                rectangle_dst.size.width += x-a;
                rectangle_src->size.width += x-a;
            }
        }
        if (flux_droite){
            if (x>a+clipper->size.width){
                return;
            }
            else{
                rectangle_dst.size.width = a + clipper->size.width - x;
                rectangle_src->size.width = a + clipper->size.width - x;
            }
        }

    }


    /*
     *  après avoir verouillé la surface du texte, on copie le contenu de rectangle_src dans rectangle_dst
     */

    hw_surface_lock(surface_texte);
    int res = ei_copy_surface(surface, &rectangle_dst, surface_texte, rectangle_src, EI_TRUE);
    hw_surface_free(surface_texte);
    hw_surface_unlock(surface);
}

/**
 * \brief	Copies pixels from a source surface to a destination surface.
 *		The source and destination areas of the copy (either the entire surfaces, or
 *		subparts) must have the same size before considering clipping.
 *		Both surfaces must be *locked* by \ref hw_surface_lock.
 */

int			ei_copy_surface		(ei_surface_t		destination, const ei_rect_t*	dst_rect, ei_surface_t		source, const ei_rect_t*	src_rect, ei_bool_t		alpha) {
    ei_size_t size_src = hw_surface_get_size(source); ei_size_t size_dst = hw_surface_get_size(destination);
    uint32_t * pixel_ptr_src = (uint32_t*) hw_surface_get_buffer(source);
    uint32_t * pixel_ptr_dst = (uint32_t*) hw_surface_get_buffer(destination);
    int width; int height;
    int a; int b; int c; int d;

    // on déclare les tailles potentielles des rectangles destination et source
    ei_size_t size_rect_src;
    ei_size_t size_rect_dst;

    /*
     Définir les:
            ** a et b, coordonnées du top_left du rectangle source,
            ** c et d, coordonnées du top_left du rectangle destination,
            ** height et width qui définissent la taille de la partie copiée.
     */

    if (dst_rect != NULL && src_rect != NULL){
        size_rect_src = src_rect->size ; size_rect_dst = dst_rect->size;
        if (size_rect_dst.width != size_rect_src.width || size_rect_dst.height != size_rect_src.height
            || (src_rect->top_left.x + src_rect->size.width) > size_src.width || (src_rect->top_left.y + src_rect->size.height) > size_src.height
            || (dst_rect->top_left.x + dst_rect->size.width) > size_dst.width || (dst_rect->top_left.y + dst_rect->size.height) > size_dst.height){
            return 1;
        }
        a = src_rect->top_left.x; b = src_rect->top_left.y;
        c = dst_rect->top_left.x; d = dst_rect->top_left.y;
        height = size_rect_src.height; width = size_rect_src.width;
    }
    else if (dst_rect != NULL){
        size_rect_dst = dst_rect->size;
        if (size_src.height != size_rect_dst.height || size_src.width != size_rect_dst.width
           || (dst_rect->top_left.x + dst_rect->size.width) > size_dst.width || (dst_rect->top_left.y + dst_rect->size.height) > size_dst.height){
            return 1;
        }
        c = dst_rect->top_left.x; d = dst_rect->top_left.y;
        a = 0; b=0;
        height = size_src.height; width = size_src.width;

    }
    else if (src_rect != NULL){
        size_rect_src = src_rect->size;
        if (size_dst.height != size_rect_src.height || size_dst.width != size_rect_src.width
            || (src_rect->top_left.x + src_rect->size.width) > size_src.width || (src_rect->top_left.y + src_rect->size.height) > size_src.height){
            return 1;
        }
        a = src_rect->top_left.x; b = src_rect->top_left.y;
        c = 0; d = 0;
        height = size_dst.height; width = size_dst.width;
    }
    else{
        if (size_src.width != size_dst.width || size_src.height != size_dst.height){
            return 1;
        }
        a = 0; b = 0; c = 0; d = 0;
        height = size_dst.height; width = size_dst.width;

    }

    /*
     Déclarer les composantes de couleurs de la source et de la destination.. à utiliser ensuite pour la transparence
    */

    //On détermine les indices des couleurs dans la source et la destination d'abord
    int ir_src; int ig_src; int ib_src; int ia_src;
    hw_surface_get_channel_indices(source, &ir_src, &ig_src, &ib_src, &ia_src);
    int ir_dst; int ig_dst; int ib_dst; int ia_dst;
    hw_surface_get_channel_indices(destination, &ir_dst, &ig_dst, &ib_dst, &ia_dst);

    /*
      Copier la surface définie pixel par pixel
    */
    uint32_t *init_src; uint32_t *init_dst;
    init_src = pixel_ptr_src + a + b*size_src.width;
    init_dst = pixel_ptr_dst + c + d*size_dst.width;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (alpha){
                //On code la transparence à partir de la formule de transparence Page 14
                uint32_t *pixel_encode_src;
                pixel_encode_src  = init_src;
                uint8_t *ptr_src = pixel_encode_src;
                uint8_t P_R = ptr_src[ir_src];
                uint8_t P_G = ptr_src[ig_src];
                uint8_t P_B = ptr_src[ib_src];
                uint8_t P_A = ptr_src[ia_src];

                uint32_t *pixel_encode_dst ;
                pixel_encode_dst  = init_dst;
                uint8_t *ptr_dst = pixel_encode_dst;
                uint8_t S_R = ptr_dst[ir_dst];
                uint8_t S_G = ptr_dst[ig_dst];
                uint8_t S_B = ptr_dst[ib_dst];

                ptr_dst[ir_dst] = (P_A * P_R + (255 - P_A) * S_R)/255;
                ptr_dst[ig_dst] = (P_A * P_G + (255 - P_A) * S_G)/255;
                ptr_dst[ib_dst] = (P_A * P_B + (255 - P_A) * S_B)/255;

                *init_dst++ = *(pixel_encode_dst);
                init_src += 1;
            }
            else {
                *(init_dst++) = *(init_src++);
            }
        }
        init_src += size_src.width - width;
        init_dst += size_dst.width - width;
    }
    return 0;


}
