#include "ei_widget.h"
#include "hw_interface.h"
#include "ei_draw.h"
#include "ei_frame.h"
#include <stdlib.h>
#include <string.h>




struct ei_widget_t* frame_allocfunc(void){
    ei_frame_t* ptr= calloc(1, sizeof (ei_frame_t));
    return (ei_widget_t*)ptr;
}


void frame_releasefunc    (struct ei_widget_t*   widget){


    free(widget->pick_color); free(widget->user_data);
    free(widget->placer_params);
    //free(widget->content_rect);
    ei_frame_t* frame=(ei_frame_t*)widget;
    //free(&(frame->text));
    //free(&(frame->img_rect));
    //free(widget->parent);   faut laisser la ref pour destroy
    // free(widget->children_head);free(widget->children_tail);  free(widget->next_sibling);  faut laisser le lien pour destroy
}

void   frame_drawfunc    (struct ei_widget_t*   widget,
                          ei_surface_t       surface,
                          ei_surface_t       pick_surface,
                          ei_rect_t*     clipper)
{
    if(((ei_frame_t*)widget)->relief!= ei_relief_none){
    ei_linked_point_t pts[4];
    ei_linked_point_t pts2[6];
    ei_linked_point_t pts3[6];
    int x0=widget->screen_location.top_left.x;
    int y0=widget->screen_location.top_left.y;
    pts[0].point.x = x0 +((ei_frame_t*)widget)->border_width; pts[0].point.y = y0+((ei_frame_t*)widget)->border_width; pts[0].next = &pts[1];
    pts[1].point.x = x0+widget->screen_location.size.width-((ei_frame_t*)widget)->border_width; pts[1].point.y = y0+((ei_frame_t*)widget)->border_width; pts[1].next = &pts[2];
    pts[2].point.x = x0+widget->screen_location.size.width-((ei_frame_t*)widget)->border_width; pts[2].point.y = y0+widget->screen_location.size.height-((ei_frame_t*)widget)->border_width; pts[2].next = &pts[3];
    pts[3].point.x = x0+((ei_frame_t*)widget)->border_width; pts[3].point.y = y0+ widget->screen_location.size.height-((ei_frame_t*)widget)->border_width; pts[3].next = NULL;
    //////////////////////////////////////////////////////////
    pts2[0].point.x = x0 ; pts2[0].point.y = y0; pts2[0].next = &pts2[1];
    pts2[1].point.x = x0+widget->screen_location.size.width; pts2[1].point.y = y0; pts2[1].next = &pts2[2];
    pts2[2].point.x = x0+widget->screen_location.size.width-((ei_frame_t*)widget)->border_width; pts2[2].point.y = y0+((ei_frame_t*)widget)->border_width; pts2[2].next = &pts2[3];
    pts2[3].point.x = x0+((ei_frame_t*)widget)->border_width; pts2[3].point.y = y0+((ei_frame_t*)widget)->border_width; pts2[3].next = &pts2[4];
    pts2[4].point.x = x0+((ei_frame_t*)widget)->border_width; pts2[4].point.y = y0+widget->screen_location.size.height-((ei_frame_t*)widget)->border_width; pts2[4].next = &pts2[5];
    pts2[5].point.x = x0; pts2[5].point.y = y0+ widget->screen_location.size.height; pts2[5].next = NULL;
    //////////////////////////////////////////////////////////
    pts3[0].point.x = x0 +widget->screen_location.size.width; pts3[0].point.y = y0+widget->screen_location.size.height; pts3[0].next = &pts3[1];
    pts3[1].point.x = x0+widget->screen_location.size.width; pts3[1].point.y = y0; pts3[1].next = &pts3[2];
    pts3[2].point.x = x0+widget->screen_location.size.width-((ei_frame_t*)widget)->border_width; pts3[2].point.y = y0+((ei_frame_t*)widget)->border_width; pts3[2].next = &pts3[3];
    pts3[3].point.x = x0-((ei_frame_t*)widget)->border_width+widget->screen_location.size.width; pts3[3].point.y = y0-((ei_frame_t*)widget)->border_width+widget->screen_location.size.height; pts3[3].next = &pts3[4];
    pts3[4].point.x = x0+((ei_frame_t*)widget)->border_width; pts3[4].point.y = y0+widget->screen_location.size.height-((ei_frame_t*)widget)->border_width; pts3[4].next = &pts3[5];
    pts3[5].point.x = x0; pts3[5].point.y = y0+ widget->screen_location.size.height; pts3[5].next = NULL;
    //////////////////////////////////////////////////////////
//    ei_frame_t* frame=(ei_frame_t*)widget;
        ei_color_t  color3 = ((ei_frame_t*)widget)->color,color2=((ei_frame_t*)widget)->color,color1=((ei_frame_t*)widget)->color;
        color1.red=(color2.red<235)?color2.red+20:255;color2.red=(color2.red>20)?color2.red-20:0;
        color1.green=(color2.green<235)?color2.green+20:255;color2.green=(color2.green>20)?color2.green-20:0;
        color1.blue=(color2.blue<235)?color2.blue+20:255;color2.blue=(color2.blue>20)?color2.blue-20:0;
        if(((ei_frame_t*)widget)->relief==ei_relief_sunken){
            ei_color_t temp =color2;
            color2=color1;color1=temp;
        }
    ei_draw_polygon    (surface,pts, color3,clipper);
    ei_draw_polygon    (pick_surface,pts,*widget->pick_color,clipper);
    ei_draw_polygon    (surface,pts2, color1,clipper);
    ei_draw_polygon    (pick_surface,pts2,*widget->pick_color,clipper);
    ei_draw_polygon    (surface,pts3, color2,clipper);
    ei_draw_polygon    (pick_surface,pts3,*widget->pick_color,clipper);
    }
    else{
        ei_linked_point_t pts[4] ;
        int x0=widget->screen_location.top_left.x;
        int y0=widget->screen_location.top_left.y;
        pts[0].point.x = x0 ; pts[0].point.y = y0; pts[0].next = &pts[1];
        pts[1].point.x = x0+widget->screen_location.size.width; pts[1].point.y = y0; pts[1].next = &pts[2];
        pts[2].point.x = x0+widget->screen_location.size.width; pts[2].point.y = y0+widget->screen_location.size.height; pts[2].next = &pts[3];
        pts[3].point.x = x0; pts[3].point.y = y0+ widget->screen_location.size.height; pts[3].next = NULL;
        ei_frame_t* frame=(ei_frame_t*)widget;
        ei_draw_polygon    (surface,pts,frame->color,clipper);
        ei_draw_polygon    (pick_surface,pts,*widget->pick_color,clipper);
    }




}


void   frame_setdefaultsfunc    (struct ei_widget_t*   widget)
{

    ei_frame_t* frame=(ei_frame_t *)widget;
    frame->color = ei_default_background_color;frame->border_width=0;frame->relief=ei_relief_none;
    frame->img=NULL;frame->img_anchor=ei_anc_center;frame->img_rect=NULL;
    frame->text=NULL;frame->text_anchor=ei_anc_center;frame->text_font=ei_default_font;frame->text_color=ei_font_default_color;
    ei_size_t size={600,600};
    widget->requested_size=size;
}

void frame_geomnotify (struct ei_widget_t*	widget, ei_rect_t		rect){
    widget->screen_location = rect;
    
}