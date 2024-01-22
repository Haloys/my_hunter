/*
** EPITECH PROJECT, 2023
** Menu
** File description:
** Menu_Control
*/

#include "../../../include/my.h"
#include "../ui_functions.h"

int refa(const sfEvent* event, const sfVector2i* mouse, const button* button)
{
    sfFloatRect buttonBounds = sfSprite_getGlobalBounds(button->sprite);

    if (event->type == sfEvtClosed) {
        return 0;
    }
    if (event->type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&buttonBounds, mouse->x, mouse->y)) {
            return 1;
        }
    }
    return 0;
}

int process_menu_events(sfRenderWindow* window, menu* menu)
{
    sfEvent event;
    sfVector2i mouse_pos;
    int result;

    while (sfRenderWindow_pollEvent(window, &event)) {
        mouse_pos = sfMouse_getPositionRenderWindow(window);
        result = refa(&event, &mouse_pos, &menu->startButton);
        if (result == 1) {
            return 1;
        }
        result = refa(&event, &mouse_pos, &menu->quitButton);
        if (result == 1) {
            return 0;
        }
    }
    return -1;
}

int show_menu(sfRenderWindow* window, const game* fig)
{
    const sfSoundBuffer* buff;
    menu menu = init_menu(window, fig);
    int status;
    sfSound* game_over_sound = init_audio("assets/audio/menu.ogg");

    sfSound_play(game_over_sound);
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        status = process_menu_events(window, &menu);
        if (status != -1) {
            break;
        }
        render_menu(window, &menu);
    }
    buff = sfSound_getBuffer(game_over_sound);
    sfSound_destroy(game_over_sound);
    sfSoundBuffer_destroy((sfSoundBuffer*)buff);
    cleanup_menu(&menu);
    return status;
}
