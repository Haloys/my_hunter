/*
** EPITECH PROJECT, 2023
** Common
** File description:
** State_Control
*/

#include "../../include/my.h"
#include "../graphics/graphics_functions.h"
#include "common_functions.h"
#include "../utils/utils_functions.h"

void reset_game_state(game *game_config)
{
    game_config->lives = 5;
    game_config->score = 0;
}

void initialize_game(game *fig, frame *frame_config, const char *bg_path)
{
    reset_game_state(fig);
    fig->num_active_sprites = 1;
    for (int i = 0; i < fig->num_active_sprites; i++) {
        fig->sprites[i] = *initialize_sprite
        ("assets/images/sprite/monster.png", frame_config, fig);
    }
    fig->crosshair = initialize_crosshair
    ("assets/images/sprite/crosshair.png");
    fig->background = init_bg(bg_path, fig->win_width, fig->win_height);
}

void initialize_random(void)
{
    srand(time(NULL));
}
