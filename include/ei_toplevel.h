
#include "ei_types.h"
#include "ei_button.h"


typedef struct ei_toplevel_t {
    ei_widget_t       widget;
    ei_color_t    color;
    int          border_width;
    char*        title;
    ei_bool_t     closable;
    ei_axis_set_t     resizable;
    ei_size_t*    min_size;
    ei_button_t * button_close;
    ei_button_t * button_resize;

} ei_toplevel_t;




struct ei_widget_t* toplevel_allocfunc(void);

void toplevel_releasefunc     (struct ei_widget_t*   widget);

ei_bool_t toplevel_handlefunc_t (struct ei_widget_t*   widget, struct ei_event_t*    event);

void   toplevel_drawfunc     (struct ei_widget_t*   widget,
                               ei_surface_t       surface,
                               ei_surface_t       pick_surface,
                               ei_rect_t*     clipper);

void   toplevel_setdefaultsfunc   (struct ei_widget_t*   widget);

