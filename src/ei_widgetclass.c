#include "ei_widget.h"
#include "ei_widgetclass.h"
#include "ei_frame.h"
#include "ei_globals.h"
#include "ei_toplevel.h"

/**
 * @brief	Registers a class to the program so that widgets of this class can be created.
 *		This must be done only once per widged class in the application.
 */

void            ei_widgetclass_register        (ei_widgetclass_t* widgetclass){

    if(!strcmp(widgetclass->name, "frame"))
    {
        widgetclass->allocfunc = &frame_allocfunc;
        widgetclass->releasefunc = &frame_releasefunc;
        widgetclass->drawfunc = &frame_drawfunc;
        widgetclass->setdefaultsfunc = &frame_setdefaultsfunc;
        //still got handle func and geomnotify to go in alll of them!
    }
    if(!strcmp(widgetclass->name, "button"))
    {
        widgetclass->allocfunc = &button_allocfunc;
        widgetclass->releasefunc = &button_releasefunc;
        widgetclass->drawfunc = &button_drawfunc;
        widgetclass->setdefaultsfunc = &button_setdefaultsfunc;
        widgetclass->handlefunc = &button_handlefunc_t;
    }
    if(!strcmp(widgetclass->name, "toplevel"))
    {
        widgetclass->allocfunc = &toplevel_allocfunc;
        widgetclass->releasefunc = &toplevel_releasefunc;
        widgetclass->drawfunc = &toplevel_drawfunc;
        widgetclass->setdefaultsfunc = &toplevel_setdefaultsfunc;
    }

    if(ptr_class_widget == NULL)
    {
        ptr_class_widget=widgetclass;
    }
    else
    {
        ei_widgetclass_t* temp = ptr_class_widget;
        widgetclass->next = temp;
        ptr_class_widget=widgetclass;
    }

}

