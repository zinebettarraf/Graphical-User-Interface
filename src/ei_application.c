#include "ei_application.h"
#include "hw_interface.h"
#include "ei_event.h"
#include "ei_widgetclass.h"
#include "ei_frame.h"
#include "ei_globals.h"
#include "ei_toplevel.h"
#include "ei_draw_suite.h"
#include "ei_historique_configuration.h"
#include <string.h>

/**
 * \brief	Creates an application.
 */

void ei_app_create(ei_size_t main_window_size, ei_bool_t fullscreen)
{
    hw_init();
    initialize_history();
    ptr_class_widget=NULL;
    ei_surface_t main_window = hw_create_window(main_window_size, fullscreen);
    ei_surface_t pick_window = hw_surface_create(main_window,main_window_size, 0);
    surface_app=main_window;
    surface_picking=pick_window;
    /* enregistrement de la classe frame*/

    ei_widgetclass_t* widgetclass_frame= calloc(1,sizeof(ei_widgetclass_t));
    strcpy(widgetclass_frame->name, "frame");
    ei_widgetclass_register     (widgetclass_frame);
    ei_widgetclass_t* widgetclass_button= calloc(1,sizeof(ei_widgetclass_t));
    strcpy(widgetclass_button->name, "button");
    ei_widgetclass_register     (widgetclass_button);
    ei_widgetclass_t* widgetclass_toplevel= calloc(1,sizeof(ei_widgetclass_t));
    strcpy(widgetclass_toplevel->name, "toplevel");
    ei_widgetclass_register     (widgetclass_toplevel);
    /*creer root une seul fois lors du la creation de l'app */
    root = ei_widget_create("frame", NULL, NULL, NULL);
    root->screen_location.top_left.x =0;
    root->screen_location.top_left.y=0;
    root->screen_location.size=hw_surface_get_size(main_window);

    hw_surface_lock    (main_window);

    hw_surface_unlock(main_window);
    hw_surface_update_rects(main_window, NULL);

}


/**
 * \brief	Releases all the resources of the application, and releases the hardware
 *		(ie. calls \ref hw_quit).
 */
void ei_app_free(void){

}



/**
 * \brief	Runs the application: enters the main event loop. Exits when
 *		\ref ei_app_quit_request is called.
 */
void ei_app_run(void){
        ask_for_stop_app = 0;
    ei_point_t* temp = malloc(sizeof(ei_point_t));
    /* desssiner */
    ei_widget_t *racine = ei_app_root_widget();
    hw_surface_lock(surface_app);
    ei_draw_recursive(racine, NULL);
    hw_surface_unlock(surface_app);
    hw_surface_update_rects(surface_app, NULL);
    /* la boucle principale du programme */
    while (!ask_for_stop_app) {
        /*attendre un evenement */
        ei_event_t event;
        hw_event_wait_next(&event);
        /* analyser l'evenement pour trouver le traitant associé */
        if (event.type == ei_ev_mouse_buttondown) {  /* cas d'evenement situé*/
            ei_widget_t *widget_touched = ei_widget_pick(&event.param.mouse.where);
            ei_button_t *button_touched = (ei_button_t *) widget_touched;
            //Dans le cas ou on l'on reconnait un bouton
            if (widget_touched!=NULL && !strcmp(widget_touched->wclass->name, "button"))
            {
                ei_bool_t consomme;
                widget_touched->wclass->handlefunc(widget_touched, &event);
                hw_surface_lock(surface_app);
                ei_draw_recursive(racine, NULL);
                hw_surface_unlock(surface_app);
                hw_surface_update_rects(surface_app, NULL);
                while (event.type != ei_ev_mouse_buttonup)
                {
                    temp->x = event.param.mouse.where.x;
                    temp->y = event.param.mouse.where.y;
                    hw_event_wait_next(&event);
                    widget_touched->wclass->handlefunc(widget_touched, &event);
                    ei_app_invalidate_rect(&widget_touched->screen_location);
                    if(ei_widget_pick(&event.param.mouse.where) != ei_widget_pick(temp))
                    {
                        hw_surface_lock(surface_app);
                        ei_draw_recursive(racine, NULL);
                        hw_surface_unlock(surface_app);
                        hw_surface_update_rects(surface_app, NULL);
                    }
                }
                rects =NULL;
                consomme = widget_touched->wclass->handlefunc(widget_touched, &event);
                hw_surface_lock(surface_app);
                ei_draw_recursive(racine, NULL);
                hw_surface_unlock(surface_app);
                hw_surface_update_rects(surface_app, NULL);
                if ( consomme == EI_TRUE){
                    ei_app_invalidate_rect(&widget_touched->screen_location);
                    button_touched->callback(widget_touched, &event, button_touched->user_param);
                    ei_app_invalidate_rect(&widget_touched->screen_location);
                }
            }

            // Dans le cas ou l'on reconnait un toplevel:
            else if (widget_touched!=NULL && !strcmp(widget_touched->wclass->name, "toplevel")){

                //On définit le toplevel et son button_resize
                ei_toplevel_t *toplevel = ((ei_toplevel_t *)widget_touched);
                ei_button_t* button_resize = toplevel->button_resize;
                ei_button_t* button_close = toplevel->button_close;

                ei_point_t* temp = malloc(sizeof(ei_point_t));
                ei_font_t     text_font=ei_default_font;
                ei_color_t	text_color	= {0xff, 0xff, 0xff, 0xff};
                ei_size_t size_text=hw_surface_get_rect(hw_text_create_surface(((ei_toplevel_t*)widget_touched)->title ,text_font,text_color)).size;


                //On relève les coordonnées du lieu de clic, et du top left de la zone cliquable pour une comparaison
                int clic_x = event.param.mouse.where.x ; int clic_y = event.param.mouse.where.y;
                int a = button_resize->widget.screen_location.top_left.x;
                int b = button_resize->widget.screen_location.top_left.y;
                int width_resize = button_resize->widget.screen_location.size.width;
                int height_resize = button_resize->widget.screen_location.size.height;
                int c = button_close->widget.screen_location.top_left.x;
                int d = button_close->widget.screen_location.top_left.y;
                int width_close = button_close->widget.screen_location.size.width;
                int height_close = button_close->widget.screen_location.size.height;

                if (clic_x>= c && clic_x <= (c+ width_close) && clic_y>= d && clic_y <= (d+ height_close)){
                    //ei_widget_destroy(widget_touched);
                    ei_rect_t y = ei_rect(widget_touched->screen_location.top_left,
                                          ei_size(widget_touched->screen_location.size.width+2*((ei_toplevel_t*)widget_touched)->border_width,
                                                  widget_touched->screen_location.size.height+size_text.height+((ei_toplevel_t*)widget_touched)->border_width));
                    ei_app_invalidate_rect(&y);
                    hw_event_wait_next(&event);
                    if (event.type == ei_ev_mouse_buttonup ){
                        //ei_widget_destroy(widget_touched);
                        hw_surface_lock(surface_app);
                        ei_widget_destroy(widget_touched);
                        ei_linked_rect_t* temp = rects;
                        //while(temp->next!=NULL){
                            //ei_rect_t* u = &temp->rect;
                            ei_draw_recursive(racine, NULL);
                            //&rects->rect
                            //temp = temp->next;
                        //}
                        hw_surface_unlock(surface_app);
                        hw_surface_update_rects(surface_app, rects);
                    }
                    rects = NULL;


                    //button_close->callback(&(button_close->widget), &event, button_touched->user_param);
                    //i can put button-callback, just like before, & define its callback!!
                }



                // On teste qu'il s'agit bien du bouton de redimensionnement

                if (clic_x>= a && clic_x <= (a+ width_resize) && clic_y>= b && clic_y <= (b+ height_resize)){

                    if (toplevel->resizable == ei_axis_x || toplevel->resizable == ei_axis_both || toplevel->resizable == ei_axis_y) {
                        while(event.type != ei_ev_mouse_buttonup){


                            //les coordonnées initiales de la souris sont a et b
                            clic_x = event.param.mouse.where.x;
                            clic_y = event.param.mouse.where.y;
                            //attendre un event en attendant un move de la souris
                            hw_event_wait_next(&event);
                            if (event.type == ei_ev_mouse_move){
                                int new_x = event.param.mouse.where.x ; int new_y = event.param.mouse.where.y;
                                if (new_x != clic_x){
                                    ei_rect_t y = ei_rect(widget_touched->screen_location.top_left,
                                                          ei_size(widget_touched->screen_location.size.width+2*((ei_toplevel_t*)widget_touched)->border_width,
                                                                  widget_touched->screen_location.size.height+size_text.height+((ei_toplevel_t*)widget_touched)->border_width));
                                    ei_app_invalidate_rect(&y);
                                    widget_touched->placer_params->w_data += new_x - clic_x;
                                    widget_touched->placer_params->h_data += new_y - clic_y;
                                    ei_app_invalidate_rect(&widget_touched->screen_location);
                                    hw_surface_lock(surface_app);
                                    ei_linked_rect_t* temp = rects;
                                    while(temp->next!=NULL){
                                        ei_rect_t* u = &temp->rect;
                                        ei_draw_recursive(racine, u);
                                        temp = temp->next;
                                    }
                                    hw_surface_unlock(surface_app);
                                    hw_surface_update_rects(surface_app, rects);
                                }
                                rects = NULL;

                            }

                        }
                    }

                }

                while (event.type != ei_ev_mouse_buttonup){
                    temp->x = event.param.mouse.where.x;
                    temp->y = event.param.mouse.where.y;
                    hw_event_wait_next(&event);
                    if(event.param.mouse.where.x!=temp->x || event.param.mouse.where.y!=temp->y){
                        ei_rect_t y = ei_rect(widget_touched->screen_location.top_left,
                                              ei_size(widget_touched->screen_location.size.width+2*((ei_toplevel_t*)widget_touched)->border_width,
                                                      widget_touched->screen_location.size.height+size_text.height+((ei_toplevel_t*)widget_touched)->border_width));
                        ei_app_invalidate_rect(&y);
                        int v = widget_touched->placer_params->x_data + event.param.mouse.where.x-temp->x;
                        int w = widget_touched->placer_params->y_data + event.param.mouse.where.y-temp->y;
                        if(v>0 && w>0 && v<root->screen_location.size.width-widget_touched->screen_location.size.width
                           && w<root->screen_location.size.height-widget_touched->screen_location.size.height){
                            widget_touched->placer_params->x_data += event.param.mouse.where.x-temp->x;
                            widget_touched->placer_params->y_data += event.param.mouse.where.y-temp->y;
                            ei_rect_t t = ei_rect(widget_touched->screen_location.top_left,
                                                  ei_size(widget_touched->screen_location.size.width+2*((ei_toplevel_t*)widget_touched)->border_width,
                                                          widget_touched->screen_location.size.height+size_text.height+((ei_toplevel_t*)widget_touched)->border_width));
                            ei_app_invalidate_rect(&t);}
                        hw_surface_lock(surface_app);
                        ei_linked_rect_t* temp = rects;
                        while(temp->next!=NULL){
                            ei_rect_t* u = &temp->rect;
                            ei_draw_recursive(racine, u);
                            temp = temp->next;
                        }
                        hw_surface_unlock(surface_app);
                        hw_surface_update_rects(surface_app, rects);

                    }
                    free(rects);
                    rects = NULL;
                }


            }
        }

        if (event.type == ei_ev_keydown)
        {  /* cas d'evenement non situé */
            while (defaultHandleFunc(&event) != EI_FALSE)
            {
                hw_event_wait_next(&event);
            }
        }
    }
}


/**
 * \brief	Adds a rectangle to the list of rectangles that must be updated on screen. The real
 *		update on the screen will be done at the right moment in the main loop.
 */
void ei_app_invalidate_rect(ei_rect_t* rect){
   if(rects == NULL)
    {
        ei_linked_rect_t* nouveau = malloc(sizeof(ei_linked_rect_t));
        nouveau->rect = *rect;
        nouveau->next = NULL;
        rects = nouveau;
    }
    else
    {
        ei_linked_rect_t* nouveau = malloc(sizeof(ei_linked_rect_t));
        nouveau->rect = *rect;
        nouveau->next = NULL;
        ei_linked_rect_t* temp = rects;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = nouveau;
    } 
}

/**
 * \brief	Tells the application to quite. Is usually called by an event handler (for example
 *		when pressing the "Escape" key).
 */
void ei_app_quit_request(void){
        ask_for_stop_app=1;
}

/**
 * \brief	Returns the "root widget" of the application: a "frame" widget that span the entire
 *		root window.
 */
ei_widget_t* ei_app_root_widget(void){
    return root;
}

/**
 * \brief	Returns the surface of the root window. Can be usesd to create surfaces with similar
 * 		r, g, b channels.
 */
ei_surface_t ei_app_root_surface(void){
    return surface_app;
}
