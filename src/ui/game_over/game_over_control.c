/*
** EPITECH PROJECT, 2023
** Game_Over
** File description:
** Game_Over_Control
*/

#include "../../../include/my.h"
#include "../ui_functions.h"

int evnt(const sfEvent* event, const sfVector2i* mouse, const button* button)
{
    sfFloatRect buttonBounds;

    if (event->type == sfEvtClosed) {
        return 1;
    }
    if (event->type == sfEvtMouseButtonPressed) {
        buttonBounds = sfSprite_getGlobalBounds(button->sprite);
        if (sfFloatRect_contains(&buttonBounds, mouse->x, mouse->y)) {
            return 0;
        }
    }
    return -1;
}

int process_game_over_events(sfRenderWindow* window, menu* menu)
{
    sfEvent event;
    sfVector2i mouse_pos;
    int result;

    while (sfRenderWindow_pollEvent(window, &event)) {
        mouse_pos = sfMouse_getPositionRenderWindow(window);
        result = evnt(&event, &mouse_pos, &menu->menuButton);
        if (result != -1) {
            return result;
        }
        result = evnt(&event, &mouse_pos, &menu->quitdefButton);
        if (result != -1) {
            return 2;
        }
        if (event.type == sfEvtClosed) {
            return 2;
        }
    }
    return -1;
}

sfSound *init_audio(const char *file_path)
{
    sfSoundBuffer* buffer = sfSoundBuffer_createFromFile(file_path);
    sfSound* sound = sfSound_create();

    sfSound_setBuffer(sound, buffer);
    return sound;
}

int show_game_over(sfRenderWindow* window, const game* fig)
{
    const sfSoundBuffer* buff;
    menu menu = init_game_over(window, fig);
    int status;
    sfSound* game_over_sound = init_audio("assets/audio/game_over.ogg");

    sfSound_play(game_over_sound);
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        status = process_game_over_events(window, &menu);
        if (status != -1) {
            break;
        }
        render_game_over(window, &menu);
    }
    cleanup_game_over(&menu);
    buff = sfSound_getBuffer(game_over_sound);
    sfSound_destroy(game_over_sound);
    sfSoundBuffer_destroy((sfSoundBuffer*)buff);
    return status;
}
