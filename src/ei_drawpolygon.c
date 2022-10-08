#include <stdlib.h>

#include "ei_types.h"
#include "ei_event.h"
#include "ei_draw.h"
#include "ei_utils.h"
#include "hw_interface.h"
#include "ei_draw_suite.h"
#include "ei_drawpolygon.h"
 
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define POS(x) (((x)>0) ? 1 : -1) 
 
    /**********************************************************************************   fill polygon  ***************************************************************************************/

ei_edge_t* ptr_fin(ei_edge_t* TCA)
{
    /* cette fonction retourne un ptr vers la dernière cellule d'une liste chainée passée en entrée*/

    ei_edge_t* edge_fin= malloc(sizeof (ei_edge_t));
    ei_edge_t* edge_par=TCA;
    while (edge_par->next_edge!=NULL)
    {
        edge_par=edge_par->next_edge;
    }
    edge_fin =edge_par;
    return edge_fin;
}

/***************************************fill polygon*****************************************************************************/

void ajout_edge(ei_edge_t*** TC ,ei_point_t point1,ei_point_t point2,int scanline_min)
{
    /* on descend tjrs de la de la scanline on calcule delta_x et delta_y dans le sens des segments vers le bas  point 1 est celui qui correspond à la scanline min*/
    ei_edge_t *new_edge = malloc(sizeof(ei_edge_t ));
    new_edge->ymax = MAX(point1.y, point2.y);
    new_edge->x_ymin = (point1.y > point2.y) ? point2.x : point1.x;
    new_edge->delta_x = (point1.y > point2.y) ? point1.x -point2.x :
                        point2.x - point1.x;
    new_edge->delta_y = abs(point1.y - point2.y);
    new_edge->E = 0;
    new_edge->next_edge = NULL;
    int ymin = MIN(point1.y, point2.y);
    if ((*TC)[ymin - scanline_min] != NULL) new_edge->next_edge=(*TC)[ymin - scanline_min];
    (*TC)[ymin - scanline_min] = new_edge;
}

void delete_edges_TCA(ei_edge_t** TCA,int scanline_courante){

    /* cette fonction supprime de TCA les côtés tels que ymax=scanline_courante*/
    if (TCA==NULL) return;
    else{
        ei_edge_t* edge_par=*TCA;
        while(edge_par!=NULL){  // ce parcours est pour supprimer tout les edges ayant ymax=scanline_courante et ne pas supprimer juste la 1er occurence
            if ((*TCA)->ymax==scanline_courante) {// supprimer du debut
                ei_edge_t* ptr_del=*TCA;
                (*TCA)=(ei_edge_t*) (*TCA)->next_edge;
                free(ptr_del);
            }
            else{
                ei_edge_t* edge_par_next=edge_par->next_edge;
                while (edge_par_next!=NULL && edge_par_next->ymax!=scanline_courante  ){
                    edge_par=edge_par_next;
                    edge_par_next=edge_par_next->next_edge;
                }
                if (edge_par_next!=NULL ){
                    ei_edge_t* ptr_del=edge_par_next;
                    edge_par->next_edge=edge_par_next->next_edge; // supprimer du milieu ou de la fin
                    free(ptr_del);
                }
            }
            edge_par=edge_par->next_edge;
        }
    }
}
ei_edge_t* Merging_two_sortedlist (ei_edge_t* a, ei_edge_t* b){
    ei_edge_t* result = NULL;
    if (a == NULL) return (b);
    else if (b == NULL) return (a);
    if (a->x_ymin <= b->x_ymin){
        result = a;
        result->next_edge = Merging_two_sortedlist(a->next_edge, b);
    }
    else{
        result = b;
        result->next_edge = Merging_two_sortedlist(a, b->next_edge);
    }
    return (result);
}
void Spliting_list(ei_edge_t* source,
                   ei_edge_t** frontRef, ei_edge_t** backRef){
    ei_edge_t* fast;
    ei_edge_t* slow;
    slow = source;
    fast = source->next_edge;
    /* La strategie des pointeurs fast/slow :  fast avance de deux noued et
     * slow avance d'un noeud à la fin fast point vers NULL et slow vers the midpoint  */
    while (fast != NULL){
        fast = fast->next_edge;
        if (fast != NULL){
            slow = slow->next_edge;
            fast = fast->next_edge;
        }
    }
    /* spliting the list */
    *frontRef = source;
    *backRef = slow->next_edge;
    slow->next_edge = NULL;
}
void Merge_sort_list(ei_edge_t** headRef){
    ei_edge_t* head = *headRef;
    ei_edge_t* a;
    ei_edge_t* b;
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next_edge == NULL)) return;
    /* Split head into 'a' and 'b' sublists */
    Spliting_list(head, &a, &b);
    /* trier recursivement les deux listes */
    Merge_sort_list(&a);
    Merge_sort_list(&b);
    /*  fusion des deux lites triées */
    *headRef = Merging_two_sortedlist(a, b);
}

void colorier_scanline (ei_surface_t surface,ei_edge_t** TCA,int scanline_courante ,ei_color_t color,const ei_rect_t* clipper){

    if (*TCA != NULL){  // on ne fait la coloration que si TCA est non NULL
        uint32_t *pixel_ptr = (uint32_t *) hw_surface_get_buffer(surface);  //adresse  du 1er pixel
        ei_edge_t *edge = *TCA;
        ei_edge_t *next = edge->next_edge;
        ei_linked_point_t* newpoint = malloc(sizeof(ei_linked_point_t));
        uint32_t  colorf = ei_map_rgba(surface, color);
        ei_point_t point;
        if (next->next_edge == NULL) { // cas d'un seul intervalle
            int x_pixel_max = next->x_ymin;
            //respecter les regles de  remplissage cas d intervalle premier inclu le second exclu
            for (int x_pixel_min = edge->x_ymin; x_pixel_min < x_pixel_max; x_pixel_min++){
                point.x =  x_pixel_min;
                point.y = scanline_courante;
                newpoint->point = point;
                color_clipped(surface, newpoint, colorf, clipper, pixel_ptr);
                // *(pixel_ptr + x_pixel_min +scanline_courante * (hw_surface_get_size(surface).width)) = ei_map_rgba(surface, color);
            }
            return;
        }
            while (next->next_edge != NULL) {// cas de plus d'un intervalle à colorer on les traite deux par deux
                int x_pixel_max = next->x_ymin;
                for (int x_pixel_min = edge->x_ymin; x_pixel_min < x_pixel_max; x_pixel_min++){
                    point.x = x_pixel_min;
                    point.y = scanline_courante;
                    newpoint->point = point;
                    color_clipped(surface, newpoint, colorf, clipper, pixel_ptr);
                    //*(pixel_ptr + x_pixel_min + scanline_courante * (hw_surface_get_size(surface).width)) = ei_map_rgba(surface, color);
                }

                edge = next->next_edge;
                next = edge->next_edge;
            }
        }

    }


int intersection_scanline (int xi,int yi ,int delta_x,int delta_y, int* E ){

    /* On utilise Bresenham pour mettre à jour l'intersection d'un edge  avec la scanline_courante
     * cette fonction retourne x_ymin de cette intersection ;on ne fait tourner l'algo de Bresenam q'une seule fois entre la scanline_courante et scanline_courante-1
     *donc la boucle de l'algo est remplacé par une condition */
    if(delta_x == 0)
        return xi;
    else if(abs(delta_y)>=abs(delta_x)){   // Bresenam usuel ->dirrigé par y
        yi+=POS(delta_y);
        *E+=abs(delta_x);
        if ( 2*(*E)> abs(delta_y)){
            xi+=POS(delta_x);
            *E-=abs(delta_y);
        }
        return xi;
    }
    else if(abs(delta_x)>abs(delta_y)){ // Bresenam adapté -> dirrigé par y dans le cas ou la pente < 1
        yi+=POS(delta_y);
        *E+=abs(delta_x);
        while ( 2*(*E) > abs(delta_y)){
            xi+=POS(delta_x);
            *E-=abs(delta_y);
        }
        return xi;
    }
}
