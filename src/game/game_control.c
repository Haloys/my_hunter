/*
** EPITECH PROJECT, 2023
** Game
** File description:
** Game_Control
*/

#include "../../include/my.h"
#include "../graphics/graphics_functions.h"
#include "game_functions.h"
#include "../events/events_functions.h"
#include "../common/common_functions.h"

int run_game(sfRenderWindow* window, game *fig, frame *ffig)
{
    gframe combined_config;
    sfClock* clock;
    spr* my_sprite;
    int game_result;
    level_audio level_audio;

    combined_config.game = *fig;
    combined_config.frame = *ffig;
    my_sprite = initialize_sprite("assets/images/sprite/monster.png",
    &combined_config.frame, &combined_config.game);
    clock = sfClock_create();
    level_audio = init_level_audio();
    game_result = game_loop(window, clock, &combined_config, &level_audio);
    initialize_random();
    cleanup(my_sprite, clock);
    cleanup_level_audio(&level_audio);
    return game_result;
}

int handle_over(sfRenderWindow* window, game *fig, frame *ffig)
{
    int game_result = run_game(window, fig, ffig);

    if (game_result == 1) {
        return handle_game_over(window, fig);
    }
    return 1;
}
