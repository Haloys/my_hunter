/*
** EPITECH PROJECT, 2023
** Common_Functions
** File description:
** Common_Function
*/

#ifndef COMMON_FUNCTIONS_H_
    #define COMMON_FUNCTIONS_H_

void initialize_game(game *fig, frame *frame_config, const char *bg_path);
void cleanup(spr* my_sprite, sfClock* clock);
void reset_game_state(game *game_config);
void initialize_random(void);

#endif
