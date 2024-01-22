/*
** EPITECH PROJECT, 2023
** Utils
** File description:
** Window
*/

#include "../../include/my.h"
#include "utils_functions.h"

sfRenderWindow* initialize_window(const game *game_config)
{
    sfVideoMode mode = {game_config->win_width, game_config->win_height, 32};

    return sfRenderWindow_create(mode, "Meow", sfResize | sfClose, NULL);
}
