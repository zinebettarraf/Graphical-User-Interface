#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "ei_types.h"
#include "hw_interface.h"
#include "ei_drawbutton.h"

typedef struct ei_button_t {
    ei_widget_t       widget;
    ei_color_t color;
    int          border_width;
    int          corner_radius;
    ei_relief_t       relief;
    char*        text;
    ei_font_t     text_font;
    ei_color_t    text_color;
    ei_anchor_t       text_anchor;
    ei_surface_t      img;
    ei_rect_t*    img_rect;
    ei_anchor_t       img_anchor;
    ei_callback_t     callback;
    void*        user_param;

} ei_button_t;

struct ei_widget_t* button_allocfunc(void);

void button_releasefunc      (struct ei_widget_t*   widget);

void   button_drawfunc      (struct ei_widget_t*   widget,
                               ei_surface_t       surface,
                               ei_surface_t       pick_surface,
                               ei_rect_t*     clipper);
void   button_setdefaultsfunc (struct ei_widget_t*   widget);

ei_bool_t button_handlefunc_t (struct ei_widget_t*   widget, struct ei_event_t*    event);

void button_geomnotify (struct ei_widget_t*	widget, ei_rect_t		rect);

 void	button_callback_t	(ei_widget_t*		widget,
                                         struct ei_event_t*	event,
                                         void*			user_param);