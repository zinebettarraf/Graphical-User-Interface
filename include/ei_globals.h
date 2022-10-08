#ifndef EI_GLOBALS_H
#define EI_GLOBALS_H

# include "ei_widgetclass.h"
#include "ei_event.h"

ei_surface_t surface_app;
ei_surface_t surface_picking;
ei_widget_t *root ;
int ask_for_stop_app;
ei_default_handle_func_t defaultHandleFunc;
ei_widgetclass_t *ptr_class_widget ;
ei_linked_rect_t* rects;
ei_widget_t* active_button;

void ei_draw_recursive(ei_widget_t * depart, ei_rect_t* clipper);

#endif