/*
** EPITECH PROJECT, 2023
** Struct
** File description:
** Game_Setup
*/

#ifndef GAME_SETUP_H_
    #define GAME_SETUP_H_

    #include "game_context.h"
    #include "game_loop_state.h"
    #include "game_frame_config.h"

typedef struct {
    game_context context;
    game_loop_state state;
    gframe *fig;
} game_st;

#endif
