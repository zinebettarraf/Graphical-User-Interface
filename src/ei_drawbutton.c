#include <stdlib.h>
#include <math.h>
#include "ei_types.h"
#include "hw_interface.h"
#include "ei_draw.h"
#include "ei_utils.h"
#include "ei_drawbutton.h"
#include "ei_button.h"
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define pi 3.1415

/* trace un arc dont les angles et rayon sont déterminés*/

ei_linked_point_t* ei_arc(ei_point_t centre, int rayon, double angle1, double angle2, ei_linked_point_t* next){
    int a = centre.x ; int b = centre.y;
    ei_linked_point_t *pts = malloc(21*sizeof(ei_linked_point_t));
    double h = (angle2 - angle1)/20;
    int i = 0;
    pts[i].point.x = a + (int)(rayon * cos(angle1));
    pts[i].point.y = b + (int)(rayon * sin(angle1));
    for (i = 1; i<=20; i++){
        pts[i].point.x = a + (int)(rayon * cos(angle1 + i*h));
        pts[i].point.y = b + (int)(rayon * sin(angle1 + i*h));
        pts[i-1].next = &(pts[i]);
    }

    pts[i-1].next = next;
    return pts;
}


/* Selon la demande, fait appel aux fonctions au-dessus pour tracer soit un top/bottom frame ou
toute une rounded frame*/

ei_linked_point_t* ei_rounded_frame (ei_rect_t rectangle, ei_bool_t Top, ei_bool_t Bottom, int corner_radius){
    ei_linked_point_t *pts ; 
    if (Top == EI_TRUE && Bottom == EI_TRUE){
        pts = ei_rounded_full_frame(rectangle, corner_radius);
    }
    else if (Top == EI_TRUE){
        pts = ei_rounded_top_frame(rectangle, corner_radius);
    }
    else{
        pts = ei_rounded_bottom_frame(rectangle, corner_radius);
    }
    return pts;
}

/* trace une "rounded frame" entière*/

ei_linked_point_t* ei_rounded_full_frame (ei_rect_t rectangle , int corner_radius){

    int a = rectangle.top_left.x; int b = rectangle.top_left.y;
    int height = rectangle.size.height; int width = rectangle.size.width;
    int rayon = corner_radius;
    ei_linked_point_t* point2 = malloc(sizeof(ei_linked_point_t));
    ei_linked_point_t* point = malloc(sizeof(ei_linked_point_t));
    point->point.x = a; point->point.y =  b+height-rayon;
    point2->point.x = a; point2->point.y =  b+rayon;
    point->next = point2;
    point2->next = NULL;

    //Le quatrième arc 
    ei_point_t centre4_2 = ei_point(a+rayon, b+height-rayon);
    ei_linked_point_t* arc4 = ei_arc(centre4_2, rayon, pi/2, pi, point);

    //le 3e arc
    ei_point_t centre3 = ei_point(a+width-rayon, b+height-rayon);
    ei_linked_point_t* arc3 = ei_arc(centre3, rayon, 0, pi/2, arc4);

    //le 2e arc
    ei_point_t centre2 = ei_point(a+width-rayon, b+rayon);
    ei_linked_point_t* arc2 = ei_arc(centre2, rayon, -pi/2, 0, arc3);

    //le 1er arc
    ei_point_t centre1 = ei_point(a+rayon, b+rayon);
    ei_linked_point_t* arc1 = ei_arc(centre1, rayon, pi, 3*pi/2, arc2);


    return arc1;
}


/* trace la partie supérieure du relief du bouton*/

ei_linked_point_t* ei_rounded_top_frame (ei_rect_t rectangle, int corner_radius){
    int a = rectangle.top_left.x; int b = rectangle.top_left.y;
    int height = rectangle.size.height; int width = rectangle.size.width;
    int rayon = corner_radius;

    ei_linked_point_t* point = malloc(sizeof(ei_linked_point_t));
    ei_linked_point_t* point2 = malloc(sizeof(ei_linked_point_t));
    point2->point.x = a+rayon; point2->point.y =  b;
    point2->next = NULL;
    point->point.x = a+height/2; point->point.y =  b+height/2;
    point->next = malloc(sizeof(ei_linked_point_t));
    point->next->point.x = a+width-height/2; point->next->point.y = b+height/2;
    point->next->next = ei_arc(ei_point(a+width-rayon, b+rayon), rayon, -pi/4, -pi/2, point2);

    //Le quatrième arc
    ei_point_t centre4 = ei_point(a+rayon, b+height-rayon);
    ei_linked_point_t* arc4 = ei_arc(centre4, rayon, pi,3*pi/4, point);


    //le 1er arc
    ei_point_t centre1 = ei_point(a+rayon, b+rayon);
    ei_linked_point_t* arc1 = ei_arc(centre1, rayon, 3*pi/2, pi, arc4);


    return arc1;
}


/* trace la partie inférieure du relief du bouton*/

ei_linked_point_t* ei_rounded_bottom_frame (ei_rect_t rectangle, int corner_radius){

    int a = rectangle.top_left.x; int b = rectangle.top_left.y;
    int height = rectangle.size.height; int width = rectangle.size.width;
    int rayon = corner_radius;

    ei_linked_point_t* point = malloc(sizeof(ei_linked_point_t));
    ei_linked_point_t* point2 = malloc(sizeof(ei_linked_point_t));
    point2->point.x = a+width-rayon; point2->point.y =  height+b;
    point2->next = NULL;
    point->point.x = a+width-height/2; point->point.y =  b+height/2;
    point->next = malloc(sizeof(ei_linked_point_t));
    point->next->point.x = a+height/2; point->next->point.y = b+height/2;
    point->next->next = ei_arc(ei_point(a+rayon, b+height-rayon), rayon, 3*pi/4, pi/2, point2);

    //Le deuxième arc
    ei_point_t centre2 = ei_point(a+width-rayon, b+rayon);
    ei_linked_point_t* arc2 = ei_arc(centre2, rayon, 0, -pi/4, point);

    //Le troisième arc
    ei_point_t centre3 = ei_point(a+width-rayon, b+height-rayon);
    ei_linked_point_t* arc3 = ei_arc(centre3, rayon, pi/2, 0, arc2);

    return arc3;
}


/*trace le bouton avec son effet relief*/

void draw_button (ei_surface_t surface,ei_surface_t pick_surface, struct ei_widget_t*   widget, ei_rect_t* clipper_ptr) {
    ei_color_t color = ((ei_button_t *)widget)->color;
    ei_rect_t rectangle = widget->screen_location;
    ei_relief_t relief = ((ei_button_t *)widget)->relief;
    int border_width = ((ei_button_t *)widget)->border_width;
    int corner_radius = ((ei_button_t *)widget)->corner_radius;
    int a = rectangle.top_left.x;
    int b = rectangle.top_left.y;
    int height = rectangle.size.height;
    int width = rectangle.size.width;
    int bord = border_width;
    ei_rect_t interieur;
    interieur.size = ei_size(width - 2 * bord, height - 2 * bord);
    interieur.top_left = ei_point(a + bord, b + bord);
    ei_color_t  color3=color,color2=color,color1=color;
    color2.red=(color2.red<235)?color2.red+30:255;color1.red=(color2.red>50)?color2.red-50:0;
    color2.green=(color2.green<235)?color2.green+30:255;color1.green=(color2.green>50)?color2.green-50:0;
    color2.blue=(color2.blue<235)?color2.blue+30:255;color1.blue=(color2.blue>50)?color2.blue-50:0;
    ei_linked_point_t* liste_top,*liste_bottom;
    liste_top = ei_rounded_frame(rectangle, EI_TRUE, EI_FALSE, corner_radius);
    liste_bottom = ei_rounded_frame(rectangle, EI_FALSE, EI_TRUE, corner_radius);
    if (relief == ei_relief_raised) {
        ei_color_t temp = color1;
        color1 = color2;
        color2 = temp;
    } else if (relief == ei_relief_none) {
        color1 = color;
        color2 = color;
    }
    ei_linked_point_t *liste_interieur = ei_rounded_frame(interieur, EI_TRUE, EI_TRUE, corner_radius);
    ei_draw_polygon(surface, liste_bottom, color2, clipper_ptr);
    ei_draw_polygon(surface, liste_top, color1, clipper_ptr);
    ei_draw_polygon(surface, liste_interieur, color3, clipper_ptr);

    ei_draw_polygon(pick_surface, liste_bottom, *widget->pick_color, clipper_ptr);
    ei_draw_polygon(pick_surface, liste_top, *widget->pick_color, clipper_ptr);
    ei_draw_polygon(pick_surface, liste_interieur, *widget->pick_color, clipper_ptr);
}