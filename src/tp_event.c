/*
 * E89 Pedagogical & Technical Lab
 * project:     tp event
 * created on:  2023-02-21 - 15:31 +0100
 * 1st author:  evan.lebihan - evan.lebihan
 * description: tp_event.c
 */

#include "stu.h"

void blit_at_origin(struct display *ds)
{
    t_bunny_position pos;

    pos.x = 0;
    pos.y = 0;
    bunny_blit(&ds->ds_win->buffer, &ds->ds_px->clipable, &pos);
    bunny_display(ds->ds_win);
}

t_bunny_response key_event(t_bunny_event_state state,
                           t_bunny_keysym keycode,
                           void *data)
{
    struct display *ds;

    ds = data;
    if (state == GO_UP)
        return (GO_ON);
    if (keycode == BKS_ESCAPE)
        return (EXIT_ON_SUCCESS);
    if (keycode == BKS_Z) {
        ds->player->y -= 1;
    }
    else if (keycode == BKS_S) {
        ds->player->y += 1;
    }
    else if (keycode == BKS_Q) {
        ds->player->x -= 1;
    }
    else if (keycode == BKS_D) {
        ds->player->x += 1;
    }
    stu_clear_pixelarray(ds->ds_px, PINK2);
    put_pixel(ds->player, ds->ds_px, WHITE);
    blit_at_origin(ds);
    return (GO_ON);
}

int main(void)
{
    struct display display;

    display.ds_win = bunny_start(800, 800, false, "fl: tp event");
    display.ds_px = bunny_new_pixelarray(800, 800);
    blit_at_origin(&display);
    display.player->x = 400;
    display.player->y = 400;
    bunny_set_key_response(key_event);
    bunny_loop(display.ds_win, 30, &display);
    bunny_stop(display.ds_win);
    return (0);
}
