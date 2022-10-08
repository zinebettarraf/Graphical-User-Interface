#include <ei_toplevel.h>
#include "ei_widget.h"
#include "ei_widgetclass.h"
#include "ei_types.h"
#include "ei_drawbutton.h"


void draw_toplevel (ei_surface_t surface, ei_surface_t pick_surface, struct ei_widget_t*   widget, ei_rect_t* clipper_ptr){

    ei_toplevel_t* my_toplevel =(ei_toplevel_t*)widget;
    ei_color_t color_base = ((ei_toplevel_t *)widget)->color;
    color_base.blue=(color_base.blue>30)?color_base.blue-30:0;
    color_base.green=(color_base.green>30)?color_base.green-30:0;
    color_base.red=(color_base.red>30)?color_base.red-30:0;
    uint32_t corner_radius=k_default_button_corner_radius;
    ei_font_t     text_font=ei_default_font;
    ei_color_t	text_color	= {0, 0, 0, 0xff};
    ei_rect_t size_text=hw_surface_get_rect(hw_text_create_surface(my_toplevel->title ,text_font,text_color));
    int border=my_toplevel->border_width;

    // traçage du rectangle de base

    ei_linked_point_t pts[4];
    int x0=widget->screen_location.top_left.x;
    int y0=widget->screen_location.top_left.y;
    pts[0].point = ei_point(x0, y0+size_text.size.height/2) ; pts[0].next = &pts[1];
    pts[1].point= ei_point(x0+widget->screen_location.size.width+2*border, y0+size_text.size.height/2) ; pts[1].next = &pts[2];
    pts[2].point= ei_point(x0+widget->screen_location.size.width+2*border, y0+widget->screen_location.size.height+border+size_text.size.height) ; pts[2].next = &pts[3];
    pts[3].point= ei_point(x0, y0+widget->screen_location.size.height+border+size_text.size.height) ; pts[3].next = NULL;
    ei_draw_polygon(surface, pts, color_base, clipper_ptr);
    ei_draw_polygon(pick_surface, pts , *widget->pick_color, clipper_ptr);


    // traçage du rectangle plus clair

    ei_linked_point_t pts_clair[4];
    x0+=border;
    pts_clair[0].point = ei_point(x0, y0+size_text.size.height) ; pts_clair[0].next = &pts_clair[1];
    pts_clair[1].point= ei_point(x0+widget->screen_location.size.width, y0+size_text.size.height) ; pts_clair[1].next = &pts_clair[2];
    pts_clair[2].point= ei_point(x0+widget->screen_location.size.width, y0+widget->screen_location.size.height+size_text.size.height) ; pts_clair[2].next = &pts_clair[3];
    pts_clair[3].point= ei_point(x0, y0+widget->screen_location.size.height+size_text.size.height) ; pts_clair[3].next = NULL;
    ei_draw_polygon(surface, pts_clair, my_toplevel->color, clipper_ptr);


    // traçage du "header" du toplevel

    ei_rect_t rect_header = ei_rect(widget->screen_location.top_left, ei_size(widget->screen_location.size.width+2*border, size_text.size.height));
    ei_linked_point_t* header = ei_rounded_full_frame(rect_header, corner_radius);
    ei_draw_polygon(surface, header, color_base, clipper_ptr);
    ei_draw_polygon(pick_surface, header, *widget->pick_color, clipper_ptr);

    // Ecriture du text dans le header

    ei_point_t where;
    where.x=rect_header.top_left.x+widget->screen_location.size.width/9; where.y= rect_header.top_left.y;
    ei_draw_text(surface,&where,((ei_toplevel_t*)widget)->title,text_font,text_color,&rect_header);



}