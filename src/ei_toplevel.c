#include "ei_widget.h"
#include "hw_interface.h"
#include "ei_toplevel.h"
#include  "ei_types.h"
#include "ei_globals.h"
#include  "ei_drawtoplevel.h"
#include <stdlib.h>
#include <string.h>





struct ei_widget_t* toplevel_allocfunc(void){
    ei_toplevel_t* ptr= calloc(1, sizeof (ei_toplevel_t));
    return (ei_widget_t*)ptr;
}


void toplevel_releasefunc     (struct ei_widget_t*   widget){


    free(widget->pick_color); free(widget->user_data);
    //  free(widget->placer_params);
    ei_toplevel_t* toplevel=(ei_toplevel_t*)widget;
    // free(&(toplevel->title));
    //  free(toplevel->min_size);
}

void   toplevel_drawfunc     (struct ei_widget_t*   widget,
                              ei_surface_t       surface,
                              ei_surface_t       pick_surface,
                              ei_rect_t*     clipper)
{
    draw_toplevel (surface, pick_surface, widget, clipper);
    ei_toplevel_t* my_toplevel =(ei_toplevel_t*)widget;
    ei_font_t     text_font=ei_default_font;
    ei_color_t text_color = {0xff, 0xff, 0xff, 0xff};
    ei_size_t size_text=hw_surface_get_rect(hw_text_create_surface(my_toplevel->title ,text_font,text_color)).size;
    int border = my_toplevel->border_width;
    if (my_toplevel->button_close!=NULL){

        ei_size_t  button_size       = ei_size(16,16);
        my_toplevel->button_close->widget.requested_size=button_size;
        int       button_x      = 10,button_y       = 5-size_text.height;
        ei_color_t button_color      = {0xff, 0x00, 0x00, 0xff};
        my_toplevel->button_close->color=button_color;
        my_toplevel->button_close->border_width=8;
        my_toplevel->button_close->relief=ei_relief_raised;
        my_toplevel->button_close->corner_radius=8;
        ei_place(my_toplevel->button_close, NULL, &button_x,&button_y , NULL, NULL, NULL, NULL, NULL, NULL );
        ei_placer_run((ei_widget_t*)(my_toplevel->button_close));
        my_toplevel->button_close->widget.wclass->drawfunc((ei_widget_t*)(my_toplevel->button_close),surface, pick_surface,  clipper);
    }

    if (my_toplevel->button_resize!=NULL){
        ei_size_t  button_resize_size    = ei_size(17,17);
        my_toplevel->button_resize->widget.requested_size=button_resize_size;
        int  button_x = widget->screen_location.size.width-17+2*border, button_y =widget->screen_location.size.height-17+border;
        ei_color_t color_base = ((ei_toplevel_t *)widget)->color;
        color_base.blue=(color_base.blue>30)?color_base.blue-30:0;
        color_base.green=(color_base.green>30)?color_base.green-30:0;
        color_base.red=(color_base.red>30)?color_base.red-30:0;
        my_toplevel->button_resize->color=color_base;
        ei_color_t button_resize_color       = color_base;

        my_toplevel->button_resize->color=button_resize_color;
        my_toplevel->button_resize->border_width=0;
        my_toplevel->button_resize->relief=ei_relief_none;
        my_toplevel->button_resize->corner_radius=1;
        ei_place(my_toplevel->button_resize, NULL, &button_x,&button_y, NULL, NULL, NULL, NULL, NULL, NULL );
        ei_placer_run((ei_widget_t*)(my_toplevel->button_resize));
        ei_button_t* my_button = (ei_widget_t*)my_toplevel->button_resize;
        my_toplevel->button_resize->widget.wclass->drawfunc(my_button,surface, pick_surface,  clipper);

    }


}

void   toplevel_setdefaultsfunc   (struct ei_widget_t*   widget)
{

    ei_toplevel_t* toplevel=(ei_toplevel_t *)widget;
    toplevel->color = ei_default_background_color;toplevel->border_width=4;toplevel->title="Toplevel";
    toplevel->closable=EI_TRUE;
    /* Par defaut on cree le boutton close on le met dans la stucture du top_level puis on supprime le lien de parenté  */
    ei_widget_t*	buttonclose;
    buttonclose= ei_widget_create("button", widget, NULL, NULL);
    buttonclose->pick_id=widget->pick_id;
    buttonclose->pick_color=widget->pick_color;
    toplevel->button_close=buttonclose;
    widget->children_head=NULL;
    widget->children_tail=NULL;
    ei_widget_t*	buttonresize;
    buttonresize= ei_widget_create("button", widget, NULL, NULL);
    buttonresize->pick_id=widget->pick_id;
    buttonresize->pick_color=widget->pick_color;
    toplevel->button_resize=buttonresize;
    widget->children_head=NULL;
    widget->children_tail=NULL;

    toplevel->resizable=ei_axis_both;
    ei_size_t size={320,240};widget->requested_size=size;
    ei_size_t size_min={160,120};toplevel->min_size=&size_min;


}

