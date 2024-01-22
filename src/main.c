/*
** EPITECH PROJECT, 2023
** Main
** File description:
** My_hunter
*/

#include "../include/my.h"
#include "ui/ui_functions.h"
#include "game/game_functions.h"
#include "common/common_functions.h"
#include "utils/utils_functions.h"

int handle_game_over(sfRenderWindow* window, game *fig)
{
    int high_scores[3];
    int game_over_result = show_game_over(window, fig);

    if (game_over_result == 0) {
        reset_game_state(fig);
        return 1;
    } else if (game_over_result == 2) {
        return 0;
    }
    return 1;
}

void initialize_game_state(game *fig, frame *ffig)
{
    fig->win_width = 1920;
    fig->win_height = 1080;
    fig->score = 0;
    fig->lives = 5;
    fig->speed = 400.0f;
    ffig->total_width = 1219;
    ffig->total_height = 290;
    ffig->num_frames = 4;
}

void main_loop(sfRenderWindow* window, game *fig, frame *ffig)
{
    while (1) {
        if (show_menu(window, fig) == 0) {
            break;
        }
        if (handle_over(window, fig, ffig) == 0) {
            break;
        }
    }
}

int main(void)
{
    game fig;
    frame ffig;
    sfRenderWindow* window;

    initialize_game_state(&fig, &ffig);
    window = initialize_window(&fig);
    initialize_game(&fig, &ffig, "assets/images/game/bg_level_1.png");
    main_loop(window, &fig, &ffig);
    sfRenderWindow_destroy(window);
    return 0;
}
