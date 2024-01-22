/*
** EPITECH PROJECT, 2023
** Events_Functions
** File description:
** Events_Functions
*/

#ifndef EVENTS_FUNCTIONS_H_
    #define EVENTS_FUNCTIONS_H_

int handle_events(sfRenderWindow* window, gframe *fig);
void mouse(sfEvent event, sfRenderWindow* win, gframe *fig);
void respawn_sprite(spr* a_sprite, int frame_width, const game *fig);
void spr_click(const sfEvent event, sfRenderWindow* win, gframe *fig);

#endif
