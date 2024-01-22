/*
** EPITECH PROJECT, 2023
** Game
** File description:
** Game_Level_Bg
*/

#include "../../include/my.h"
#include "game_functions.h"
#include "../utils/utils_functions.h"

const char *level_backgrounds[5] = {
    "assets/images/game/bg_level_1.png",
    "assets/images/game/bg_level_2.png",
    "assets/images/game/bg_level_3.png",
    "assets/images/game/bg_level_4.png",
    "assets/images/game/bg_level_5.png"
};

void change_background(game *fig, int level)
{
    if (level < 0 || level >= 5) {
        return;
    }
    if (fig->background != NULL) {
        sfSprite_destroy(fig->background);
    }
    fig->background = init_bg(level_backgrounds[level],
    fig->win_width, fig->win_height);
}
