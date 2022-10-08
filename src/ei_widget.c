#include "ei_widget.h"
#include "ei_widgetclass.h"
#include "ei_frame.h"
#include "ei_globals.h"
#include "ei_placer.h"
//#include "ei_button.h"
#include "ei_toplevel.h"
#include "ei_historique_configuration.h"
#include <stdlib.h>
#include <stdint.h>


ei_color_t pick_color={0,0,0,0xff};

void         ei_frame_configure    (ei_widget_t*     widget,
                                    ei_size_t*     requested_size,
                                    const ei_color_t*   color,
                                    int*          border_width,
                                    ei_relief_t*       relief,
                                    char**        text,
                                    ei_font_t*     text_font,
                                    ei_color_t*    text_color,
                                    ei_anchor_t*       text_anchor,
                                    ei_surface_t*      img,
                                    ei_rect_t**    img_rect,
                                    ei_anchor_t*       img_anchor)

{    ei_historique_frame_t* temp=historique_configuration->histo_frame;
    /* l'initialisation du  widget à configurer par les valeurs par defaut se fait dans la phase de sa création*/
    ei_frame_t* frame=(ei_frame_t*)widget;
    if (requested_size!=NULL) {
        frame->widget.requested_size=*(requested_size);
        historique_configuration->histo_frame->requested_size=requested_size;
    }
    else if (historique_configuration->histo_frame->requested_size!=NULL) widget->requested_size=*(historique_configuration->histo_frame->requested_size);
    if (color!=NULL) {
        frame->color=*(color);
        historique_configuration->histo_frame->color=color;

    }
    else if (historique_configuration->histo_frame->color!=NULL) frame->color=*(historique_configuration->histo_frame->color);
    if (border_width!=NULL) {
        frame->border_width=*(border_width);
        historique_configuration->histo_frame->border_width=(border_width);
    }
    else if (historique_configuration->histo_frame->border_width!=NULL) frame->border_width=*(historique_configuration->histo_frame->border_width);
    if (relief!=NULL) {
        frame->relief=*(relief);
        historique_configuration->histo_frame->relief=relief;
    }
    else if (historique_configuration->histo_frame->relief!=NULL) frame->relief=*(historique_configuration->histo_frame->relief);
    if (text!=NULL) {
        frame->text=*(text);
        historique_configuration->histo_frame->text=text;
    }
    else if (historique_configuration->histo_frame->text!=NULL) frame->text=*(historique_configuration->histo_frame->text);
    if (text_font!=NULL) {
        frame->text_font=*(text_font);
        historique_configuration->histo_frame->text_font=text_font;
    }
    else if (historique_configuration->histo_frame->text_font!=NULL) frame->text_font=*(historique_configuration->histo_frame->text_font);
    if (text_color!=NULL) {
        frame->text_color=*(text_color);
        historique_configuration->histo_frame->text_color=text_color;
    }
    else if (historique_configuration->histo_frame->text_color!=NULL) frame->text_color=*(historique_configuration->histo_frame->text_color);
    if (text_anchor!=NULL) {
        frame->text_anchor=*(text_anchor);
        historique_configuration->histo_frame->text_anchor=text_anchor;
    }
    else if (historique_configuration->histo_frame->text_anchor!=NULL) frame->text_anchor=*(historique_configuration->histo_frame->text_anchor);
    if (img!=NULL) {
        ei_rect_t rectsource =hw_surface_get_rect(*(img));
        frame->img= hw_surface_create(surface_app,rectsource.size,EI_FALSE);
        hw_surface_lock(frame->img);
        ei_copy_surface       (frame->img,NULL,*(img),NULL,EI_FALSE);
        hw_surface_unlock(frame->img);
    }
    else if (historique_configuration->histo_frame->img!=NULL) frame->img=*(historique_configuration->histo_frame->img);
    if (img_rect!=NULL) {
        frame->img_rect=*(img_rect);
        historique_configuration->histo_frame->img_rect=img_rect;
    }
    else if (historique_configuration->histo_frame->img_rect!=NULL) frame->img_rect=*(historique_configuration->histo_frame->img_rect);
    if (img_anchor!=NULL) {
        frame->img_anchor=*(img_anchor);
        historique_configuration->histo_frame->img_anchor=img_anchor;
    }
    else if (historique_configuration->histo_frame->img_anchor!=NULL) frame->img_anchor=*(historique_configuration->histo_frame->img_anchor);
}
void         ei_button_configure       (ei_widget_t*     widget,
                                        ei_size_t*    requested_size,
                                        const ei_color_t*  color,
                                        int*         border_width,
                                        int*         corner_radius,
                                        ei_relief_t*      relief,
                                        char**       text,
                                        ei_font_t*    text_font,
                                        ei_color_t*       text_color,
                                        ei_anchor_t*      text_anchor,
                                        ei_surface_t*     img,
                                        ei_rect_t**       img_rect,
                                        ei_anchor_t*      img_anchor,
                                        ei_callback_t*    callback,
                                        void**       user_param)
{
    ei_button_t* button = (ei_button_t*)widget;
    if (requested_size!=NULL){
        widget->requested_size=*(requested_size);
        historique_configuration->histo_button->requested_size=requested_size;
    }
    else if (historique_configuration->histo_button->requested_size!=NULL) widget->requested_size=*(historique_configuration->histo_button->requested_size);
    if (color!=NULL) {
        button->color=*(color);
        historique_configuration->histo_button->color=color;
    }
    else if (historique_configuration->histo_button->color!=NULL) button->color=*(historique_configuration->histo_button->color);
    if (border_width!=NULL){
        button->border_width=*(border_width);
        historique_configuration->histo_button->border_width=border_width;
    }
    else if (historique_configuration->histo_button->border_width!=NULL) button->border_width=*(historique_configuration->histo_button->border_width);
    if (corner_radius!=NULL){
        button->corner_radius=*(corner_radius);
        historique_configuration->histo_button->corner_radius=corner_radius;
    }
    else if (historique_configuration->histo_button->corner_radius!=NULL) button->corner_radius=*(historique_configuration->histo_button->corner_radius);
    if (relief!=NULL){
        button->relief=*(relief);
        historique_configuration->histo_button->relief=relief;
    }
    else if (historique_configuration->histo_button->relief!=NULL) button->relief=*(historique_configuration->histo_button->relief);
    if (text!=NULL) {
        button->text=*(text);
        historique_configuration->histo_button->text=text;
    }
    else if (historique_configuration->histo_button->text!=NULL) button->text=*(historique_configuration->histo_button->text);
    if (text_font!=NULL) {
        button->text_font=*(text_font);
        historique_configuration->histo_button->text_font=text_font;
    }
    else if (historique_configuration->histo_button->text_font!=NULL) button->text_font=*(historique_configuration->histo_button->text_font);
    if (text_color!=NULL) {
        button->text_color=*(text_color);
        historique_configuration->histo_button->text_color=text_color;
    }
    else if (historique_configuration->histo_button->text_color!=NULL) button->text_color=*(historique_configuration->histo_button->text_color);
    if (text_anchor!=NULL) {
        button->text_anchor=*text_anchor;
        historique_configuration->histo_button->text_anchor=text_anchor;
    }
    else if (historique_configuration->histo_button->text_anchor!=NULL) button->text_anchor=*(historique_configuration->histo_button->text_anchor);
    if (img!=NULL) {
        ei_rect_t rectsource =hw_surface_get_rect(*(img));
        button->img= hw_surface_create(surface_app,rectsource.size,EI_FALSE);
        hw_surface_lock(button->img);
        ei_copy_surface       (button->img,NULL,*(img),NULL,EI_FALSE);
        hw_surface_unlock(button->img);
        historique_configuration->histo_button->img=img;

    }
    else if (historique_configuration->histo_button->img!=NULL) button->img=*(historique_configuration->histo_button->img);
    if (img_rect!=NULL) {
        button->img_rect=*(img_rect);
        historique_configuration->histo_button->img_rect=img_rect;
    }
    else if (historique_configuration->histo_button->img_rect!=NULL) button->img_rect=*(historique_configuration->histo_button->img_rect);
    if (img_anchor!=NULL) {
        button->img_anchor=*(img_anchor);
        historique_configuration->histo_button->img_anchor=img_anchor;
    }
    else if (historique_configuration->histo_button->img_anchor!=NULL) button->img_anchor=*(historique_configuration->histo_button->img_anchor);
    if (callback!=NULL) {
        button->callback = *callback;
        historique_configuration->histo_button->callback=callback;
    }
    else if (historique_configuration->histo_button->callback!=NULL) button->callback=*(historique_configuration->histo_button->callback);
    if (user_param!=NULL) {
        button->user_param=*(user_param);
        historique_configuration->histo_button->user_param=user_param;
    }
    else if (historique_configuration->histo_button->user_param!=NULL) button->user_param=*(historique_configuration->histo_button->user_param);



}
void         ei_toplevel_configure     (ei_widget_t*     widget,
                                        ei_size_t*      requested_size,
                                        ei_color_t*     color,
                                        int*       border_width,
                                        char**         title,
                                        ei_bool_t*      closable,
                                        ei_axis_set_t*      resizable,
                                        ei_size_t**     min_size){

    ei_toplevel_t* toplevel = (ei_toplevel_t*)widget;
    if (requested_size!=NULL) {
        widget->requested_size=*(requested_size);
        historique_configuration->histo_toplevel->requested_size=requested_size;
    }
    else if (historique_configuration->histo_toplevel->requested_size!=NULL) widget->requested_size=*(historique_configuration->histo_toplevel->requested_size);
    if (color!=NULL) {
        toplevel->color=*(color);
        historique_configuration->histo_toplevel->color=color;
    }
    else if (historique_configuration->histo_toplevel->color!=NULL) toplevel->color=*(historique_configuration->histo_toplevel->color);
    if (border_width!=NULL) {
        toplevel->border_width=*(border_width);
        historique_configuration->histo_toplevel->border_width=border_width;
    }
    else if (historique_configuration->histo_toplevel->border_width!=NULL) toplevel->border_width=*(historique_configuration->histo_toplevel->border_width);
    if (*title!=NULL) {
        toplevel->title=*(title);
        historique_configuration->histo_toplevel->title=title;
    }
    else if (historique_configuration->histo_toplevel->title!=NULL) toplevel->title=*(historique_configuration->histo_toplevel->title);
    if (closable!=NULL) {
        toplevel->closable=*(closable);
        historique_configuration->histo_toplevel->closable=closable;
    }
    else if (historique_configuration->histo_toplevel->closable!=NULL) toplevel->closable=*(historique_configuration->histo_toplevel->closable);
    if (resizable!=NULL) {
        toplevel->resizable=*(resizable);
        historique_configuration->histo_toplevel->resizable=resizable;
    }
    else if (historique_configuration->histo_toplevel->resizable!=NULL) toplevel->resizable=*(historique_configuration->histo_toplevel->resizable);
    if (min_size!=NULL) {
        toplevel->min_size=*(min_size);
        historique_configuration->histo_toplevel->min_size=min_size;
    }
    else if (historique_configuration->histo_toplevel->min_size!=NULL) toplevel->min_size=*(historique_configuration->histo_toplevel->min_size);

}


void          ei_widget_destroy     (ei_widget_t*     widget) {
    ei_widget_destructor_t destructor = widget->destructor;

    //On ajuste l'hiérarchie d'abord

    //si le widget est le children_head de son parent, il faut modifier ça en sauvegardant le reste de l'hiérarchie
    if (widget->parent->children_head == widget){
        // Si jamais il est le seul fils, le parent n'aura plus d'enfants
        if (widget->parent->children_tail == widget){
            widget->parent->children_head = NULL;
            widget->parent->children_tail = NULL;
        }
            //Sinon le head devient le 2e "child" du parent
        else{
            widget->parent->children_head = widget->next_sibling;
        }

    }
        //si le widget est le children_tail de son parent, il faut modifier ça en sauvegardant le reste de l'hiérarchie
    else if (widget->parent->children_tail == widget){
        ei_widget_t * current = widget->parent->children_head;
        ei_widget_t * next = current->next_sibling;

        while(next != widget){
            current = current->next_sibling;
            next = next->next_sibling;
        }
        current->next_sibling = NULL;
        widget->parent->children_tail = current;

    }
        // Modifier l'hiérarchie dans tous les autres cas
    else{
        ei_widget_t * current = widget->parent->children_head;
        ei_widget_t * next = current->next_sibling;
        while (next != widget){
            current = current->next_sibling;
            next = next->next_sibling;
        }
        current = next->next_sibling;
    }


    //On supprime le widget et tous ses enfants par récursivité
    if (widget->children_head == NULL){
        //On appelle le destructeur dans le cas ou il est fourni
        if (destructor != NULL){

        }

        widget->wclass->releasefunc(widget);
    }
    else{
        ei_widget_t * current = widget->parent->children_head;
        while (current != NULL){
            ei_widget_destroy(current);
            current = current->next_sibling;
        }
        widget->wclass->releasefunc(widget);
    }

}
void ei_recherche_recursive(ei_widget_t * depart,uint32_t color_off_encode, ei_widget_t ** resultat)
{
    if ( ei_map_rgba(surface_picking,*(depart->pick_color))==color_off_encode){
        *resultat = depart;

    }
    else{
        ei_widget_t* ptr = depart->children_head;

        while(ptr!=NULL)
        {
            ei_recherche_recursive(ptr,color_off_encode, resultat);
            ptr = ptr->next_sibling;
        }
    }

}




ei_widget_t*        ei_widget_pick            (ei_point_t*        where){

    uint32_t *pixel_ptr = (uint32_t *) hw_surface_get_buffer(surface_picking);  //adresse  du 1er pixel dans l'offscreen
    uint32_t color_off_encode= *(pixel_ptr + where->x + where->y * (hw_surface_get_size(surface_picking).width));
    ei_widget_t* pt;
    ei_recherche_recursive(root,color_off_encode, &pt);
    return pt;
}



ei_widget_t*      ei_widget_create      (ei_widgetclass_name_t class_name,
                                         ei_widget_t*     parent,
                                         void*       user_data,
                                         ei_widget_destructor_t destructor){

    uint32_t pick_id = ei_map_rgba (surface_app, pick_color);
    ei_widgetclass_t* temp = ptr_class_widget;
    while(strcmp(temp->name,class_name)){
        temp = temp->next;
    }
    ei_widget_t* widget=(temp->allocfunc());
    widget->wclass=temp;
    widget->parent=parent;
    widget->next_sibling = NULL;
    if (widget->parent!= NULL){
        if(parent->children_head == NULL) {
            widget->parent->children_head = widget;
            widget->parent->children_tail = widget;
        }
        else{
            widget->parent->children_tail->next_sibling = widget;
            widget->parent->children_tail = widget;
        }
    }
    widget->pick_color = malloc(sizeof(ei_color_t));
    widget->wclass->setdefaultsfunc(widget);
    widget->content_rect = malloc(sizeof(ei_rect_t));
    widget->content_rect = &(widget->screen_location);
    widget->pick_id = pick_id;
    *widget->pick_color = pick_color;
    if(pick_color.green<255) pick_color.green++;
    else if(pick_color.red<255){
        pick_color.green=0;
        pick_color.red++;
    }
    else  {
        pick_color.green=0;
        pick_color.red=0;
        pick_color.blue++;
    }
    return  widget;


}














