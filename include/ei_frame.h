#include "ei_widget.h"
#include "ei_widgetclass.h"
#include "ei_types.h"


typedef struct ei_frame_t {
    ei_widget_t		widget;
    ei_color_t	color;
    int border_width;
    ei_relief_t		relief;
    char*	text;
    ei_font_t		text_font;
    ei_color_t		text_color;
    ei_anchor_t		text_anchor;
    ei_surface_t		img;
    ei_rect_t*		img_rect;
    ei_anchor_t		img_anchor;

} ei_frame_t;




struct ei_widget_t* frame_allocfunc(void);

void frame_releasefunc		(struct ei_widget_t*	widget);

void	frame_drawfunc		(struct ei_widget_t*	widget,
                               ei_surface_t		surface,
                               ei_surface_t		pick_surface,
                               ei_rect_t*		clipper);

void	frame_setdefaultsfunc	(struct ei_widget_t*	widget);