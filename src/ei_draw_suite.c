#include <stdint.h>
#include <stdlib.h>
#include "ei_types.h"
#include "hw_interface.h"

void color_clipped (ei_surface_t surface, ei_linked_point_t* linkedpoint, uint32_t  color,const ei_rect_t* clipper, uint32_t *	pixel_ptr){
    if (clipper){
        int a = clipper->top_left.x;
        int b = clipper->top_left.y;
        int m = clipper->size.width;
        int n = clipper->size.height;
        if ((linkedpoint->point).y <= b+n && a <= (linkedpoint->point).x && (linkedpoint->point).x <= a+m &&  b <= (linkedpoint->point).y ){
            *(pixel_ptr + (linkedpoint->point).x + ((linkedpoint->point).y)*hw_surface_get_size(surface).width) = color;
        }
    }
    else{
        *(pixel_ptr + (linkedpoint->point).x + ((linkedpoint->point).y)*hw_surface_get_size(surface).width) = color;
    }

}
