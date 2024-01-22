/*
** EPITECH PROJECT, 2023
** Game_Functions
** File description:
** Game_Functions
*/

#ifndef GAME_FUNCTIONS_H_
    #define GAME_FUNCTIONS_H_

int handle_game_over(sfRenderWindow* window, game *fig);
int run_game(sfRenderWindow* window, game *fig, frame *ffig);
int handle_over(sfRenderWindow* window, game *fig, frame *ffig);
void init_game(sfRenderWindow* win, sfClock* c, level_audio* la, game_st *st);
int process_game(game_context *context, gframe *fig, game_loop_state *state);
int game_loop(sfRenderWindow* win, sfClock* c, gframe *fig, level_audio* la);
void sprite_status(spr* my_sprite, float delta_time, frame *ffig, game *fig);
int calculate_level(int score);
level_audio init_level_audio(void);
void cleanup_level_audio(level_audio* la);
void handle_level(level_audio* la, int score);
void change_background(game *fig, int level);

#endif
