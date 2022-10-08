#include "ei_widget.h"
#include "hw_interface.h"
#include "ei_button.h"
#include "ei_event.h"
#include "ei_globals.h"
#include <stdlib.h>
#include <string.h>


struct ei_widget_t* button_allocfunc(void){
    ei_button_t* ptr= calloc(1, sizeof (ei_button_t));
    return (ei_widget_t*)ptr;
}


void button_releasefunc       (struct ei_widget_t*   widget){


    free(widget->pick_color); free(widget->user_data);
    free(widget->placer_params);
    //   ei_button_t * button=(ei_button_t *)widget;
//    free(button->user_param);
}
void   button_drawfunc       (struct ei_widget_t*   widget,
                              ei_surface_t       surface,
                              ei_surface_t       pick_surface,
                              ei_rect_t*     clipper)
{
    draw_button (surface,pick_surface, widget, clipper);
    ei_point_t where;
    ei_button_t* button= (ei_button_t*)widget;
    if(button->text!=NULL){
        ei_rect_t size_text=hw_surface_get_rect(hw_text_create_surface(button->text,button->text_font,button->text_color));
        if(button->text_anchor==ei_anc_center){
            where.x=widget->screen_location.top_left.x+widget->screen_location.size.width/2-size_text.size.width/2;
            where.y=widget->screen_location.top_left.y+widget->screen_location.size.height/2-size_text.size.height/2;
        }
        else if (button->text_anchor==ei_anc_north){
            where.x=widget->screen_location.top_left.x+widget->screen_location.size.width/2-size_text.size.width/2;
            where.y=widget->screen_location.top_left.y+button->border_width;
        }
        else if (button->text_anchor==ei_anc_northeast){
            where.x=widget->screen_location.top_left.x+widget->screen_location.size.width-size_text.size.width-button->border_width;
            where.y=widget->screen_location.top_left.y+button->border_width;
        }
        else if (button->text_anchor==ei_anc_northwest) {
            where.x=widget->screen_location.top_left.x+button->border_width;
            where.y=widget->screen_location.top_left.y+button->border_width;
        }
        else if (button->text_anchor== ei_anc_east){
            where.x=widget->screen_location.top_left.x+widget->screen_location.size.width-size_text.size.width-button->border_width;
            where.y=widget->screen_location.top_left.y+widget->screen_location.size.height/2-size_text.size.height/2;
        }
        else if (button->text_anchor==ei_anc_west){
            where.x=widget->screen_location.top_left.x+button->border_width;
            where.y=widget->screen_location.top_left.y+widget->screen_location.size.height/2-size_text.size.height/2;
        }
        else if (button->text_anchor==ei_anc_southeast){
            where.x=widget->screen_location.top_left.x+widget->screen_location.size.width-size_text.size.width-button->border_width;
            where.y=widget->screen_location.top_left.y+widget->screen_location.size.height-size_text.size.height-button->border_width;
        }
        else if (button->text_anchor==ei_anc_south){
            where.x=widget->screen_location.top_left.x+widget->screen_location.size.width/2-size_text.size.width/2;
            where.y=widget->screen_location.top_left.y+widget->screen_location.size.height-size_text.size.height-button->border_width;
        }
        else if (button->text_anchor==ei_anc_southwest){
            where.x=widget->screen_location.top_left.x+button->border_width;
            where.y=widget->screen_location.top_left.y+widget->screen_location.size.height-size_text.size.height-button->border_width;
        }

        ei_draw_text(surface,&where,button->text,button->text_font,button->text_color,&button->widget.parent->screen_location);
    }
    if(button->img!=NULL){
        hw_surface_lock(surface);
        ei_rect_t rect_dessin= ei_rect(ei_point(widget->screen_location.top_left.x+button->border_width,widget->screen_location.top_left.y+button->border_width),
                                       ei_size(widget->screen_location.size.width-2*button->border_width,widget->screen_location.size.height-2*button->border_width));
        ei_copy_surface    (surface,&rect_dessin,button->img,&rect_dessin,EI_TRUE);
        hw_surface_unlock(surface);
        hw_surface_update_rects(surface, NULL);
    }

}



void   button_setdefaultsfunc   (struct ei_widget_t*   widget)
{

    ei_button_t* button=(ei_button_t *)widget;
    button->corner_radius=k_default_button_corner_radius;
    button->callback=NULL; button->user_param=NULL;
    button->color = ei_default_background_color;button->border_width=k_default_button_border_width;button->relief=ei_relief_raised;
    button->img=NULL;button->img_anchor=ei_anc_center;button->img_rect=NULL;
    button->text=NULL;button->text_anchor=ei_anc_center;button->text_font=ei_default_font;button->text_color=ei_font_default_color;
    ei_size_t size={50,30};
    widget->requested_size=size;
}



ei_bool_t button_handlefunc_t (struct ei_widget_t*   widget, struct ei_event_t*    event){

    if(ei_widget_pick(&event->param.mouse.where)!=widget)
    {
        ((ei_button_t*)widget)->relief = ei_relief_raised;
    }
    else
    {
        ((ei_button_t *) widget)->relief = ei_relief_sunken;
    }
    if(event->type != ei_ev_mouse_buttonup || ei_widget_pick(&event->param.mouse.where)!=widget)
    {
        return EI_FALSE;
    }
    if(event->type != ei_ev_mouse_buttondown && ei_widget_pick(&event->param.mouse.where)==widget)
    {
        ((ei_button_t*)widget)->relief = ei_relief_raised;
        return EI_TRUE;
    }
}