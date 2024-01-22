/*
** EPITECH PROJECT, 2023
** Events
** File description:
** Sprite_Interaction
*/

#include "../../include/my.h"
#include "events_functions.h"

int handle_events(sfRenderWindow* window, gframe *fig)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            return 0;
        }
        mouse(event, window, fig);
    }
    return 1;
}

void mouse(sfEvent event, sfRenderWindow* win, gframe *fig)
{
    if (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == sfMouseLeft) {
        spr_click(event, win, fig);
    }
}
