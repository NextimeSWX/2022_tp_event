/*
 * E89 Pedagogical & Technical Lab
 * project:     Rev
 * created on:  2022-11-22 - 09:48 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: stu.h
 */

#ifndef STU_H_
#define STU_H_

#include <lapin.h>

struct display {
    t_bunny_window *ds_win;
    t_bunny_pixelarray *ds_px;
    t_bunny_position *player;
};
void blit_at_origin(struct display *ds);
t_bunny_response key_event(t_bunny_event_state state,
                           t_bunny_keysym keycode,
                           void *data);
void put_pixel(t_bunny_position *pos,
               t_bunny_pixelarray *px,
               unsigned int color);
void stu_clear_pixelarray(t_bunny_pixelarray *pxa, unsigned int color);

#endif
