# include "ei_widgetclass.h"
#include "ei_event.h"
#include "ei_application.h"
#include "ei_globals.h"


void ei_draw_recursive(ei_widget_t * depart, ei_rect_t* clipper)
{
    if (depart != ei_app_root_widget()){ei_placer_run(depart);}
    depart->wclass->drawfunc(depart, surface_app, surface_picking, clipper);
    ei_widget_t* ptr = depart->children_head;
    while(ptr!= NULL) {
        ei_draw_recursive(ptr, clipper);
        ptr = ptr->next_sibling;
    }
}