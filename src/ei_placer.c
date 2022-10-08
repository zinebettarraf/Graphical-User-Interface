#include "ei_placer.h"
#include "ei_widget.h"
#include "ei_toplevel.h"
//#include "ei_button.h"
#include "hw_interface.h"

void        ei_place    (struct ei_widget_t*    widget,
                         ei_anchor_t*        anchor,
                         int*            x,
                         int*            y,
                         int*            width,
                         int*            height,
                         float*            rel_x,
                         float*            rel_y,
                         float*            rel_width,
                         float*            rel_height)
{

    ei_placer_params_t *widget_placer = malloc(sizeof(ei_placer_params_t));
    widget_placer->anchor = anchor;
    widget_placer->anchor_data = (anchor == NULL)? ei_anc_northwest : *anchor;
    int x_abs = (x==NULL)? 0 : *x;
    float x_rel = (rel_x==NULL)? 0.0: *rel_x;
    widget_placer->x = x;
    widget_placer->x_data = x_abs;
    widget_placer->rx = rel_x;
    widget_placer->rx_data =  x_rel;
    int y_abs = (y==NULL)? 0 : *y;
    ei_font_t     text_font=ei_default_font;
    ei_color_t text_color = {0xff, 0xff, 0xff, 0xff};
    if(!strcmp(widget->parent->wclass->name, "toplevel")){
        ei_size_t size_text=hw_surface_get_rect(hw_text_create_surface(((ei_toplevel_t*)widget->parent)->title ,text_font,text_color)).size;
        y_abs+=size_text.height;
    }
    float y_rel = (rel_y==NULL)? 0.0: *rel_y;
    widget_placer->y = y;
    widget_placer->y_data =  y_abs;
    widget_placer->ry = rel_y;
    widget_placer->ry_data =  y_rel;
    int width_abs = (width==NULL)? 0 : *width;
    float width_rel = (rel_width==NULL)? 0.0 : *rel_width;
    if(width == NULL && rel_width==NULL)
        width_abs=widget->requested_size.width ;
    widget_placer->w = width;
    widget_placer->w_data =  width_abs;
    widget_placer->rw = rel_width;
    widget_placer->rw_data =  width_rel;
    int height_abs = (height==NULL)? 0: *height;
    float  height_rel = (rel_height==NULL)? 0.0 : *rel_height;
    if(height == NULL && rel_height==NULL)
        height_abs=widget->requested_size.height;
    widget_placer->h = height;
    widget_placer->h_data =  height_abs;
    widget_placer->rh = rel_height;
    widget_placer->rh_data =  height_rel;
    widget->placer_params=widget_placer;
}



void ei_placer_run(struct ei_widget_t* widget){

    /* point de depart en absolu */
    ei_point_t abs_pt;
    abs_pt.x=(widget->placer_params->rx==NULL)?widget->placer_params->x_data+ widget->parent->content_rect->top_left.x:
             widget->parent->content_rect->top_left.x+(int)((widget->placer_params->rx_data) *((float)( widget->parent->content_rect->size.width)))+widget->placer_params->x_data;
    abs_pt.y=(widget->placer_params->ry==NULL)?widget->placer_params->y_data+ widget->parent->content_rect->top_left.y:
             widget->parent->content_rect->top_left.y+(int) ((widget->placer_params->ry_data) *((float)( widget->parent->content_rect->size.height)))+widget->placer_params->y_data;
    /* width and height en absolu*/
    int width_abs=(int)(widget->placer_params->rw_data *(float)widget->parent->content_rect->size.width+widget->placer_params->w_data);
    int height_abs=(int)((widget->placer_params->rh_data) *((float)( widget->parent->content_rect->size.height)))+widget->placer_params->h_data;
    ei_size_t  size_widget ;
    size_widget.width=width_abs;
    size_widget.height=height_abs;
    widget->screen_location.size=size_widget;
    /*  */
    if (widget->placer_params->anchor_data == ei_anc_center){
        abs_pt.x-=width_abs/2;
        abs_pt.y-=height_abs/2;
    }
    else if (widget->placer_params->anchor_data == ei_anc_north) abs_pt.x-=(int)(width_abs/2);
    else if (widget->placer_params->anchor_data == ei_anc_northeast) abs_pt.x-=width_abs;
    else if (widget->placer_params->anchor_data == ei_anc_east){
        abs_pt.x-=width_abs;
        abs_pt.y-=height_abs/2;
    }
    else if (widget->placer_params->anchor_data== ei_anc_southeast){
        abs_pt.x-=width_abs;
        abs_pt.y-=height_abs;
    }
    else if (widget->placer_params->anchor_data == ei_anc_south){
        abs_pt.x-=width_abs/2;
        abs_pt.y-=height_abs;
    }
    else if (widget->placer_params->anchor_data == ei_anc_southwest) abs_pt.y-=height_abs;
    else if (widget->placer_params->anchor_data == ei_anc_west)  abs_pt.y-=height_abs/2;
    widget->screen_location.top_left=abs_pt;

    /* gestion de la size du widget suite  à un changement de son label*/

//    if(!strcmp(widget->wclass->name, "button"))
//    {   ei_button_t* my_button =(ei_button_t*)widget;
//        if (my_button->text!=NULL){
//            ei_size_t size_text=hw_surface_get_rect(hw_text_create_surface(my_button->text,my_button->text_font,my_button->text_color)).size;
//            if (size_text.width > widget->screen_location.size.width)  {
//                if (size_text.width > widget->parent->screen_location.size.width)
//                    widget->screen_location.size.width=widget->parent->screen_location.size.width+2*(my_button->corner_radius)+20;
//                else widget->screen_location.size.width=size_text.width+2*(my_button->corner_radius);
//            }
//            if (size_text.height > widget->screen_location.size.height) widget->parent->screen_location.size.height=size_text.height;
//        }
//
//    }


    *(widget->content_rect)= widget->screen_location;



}