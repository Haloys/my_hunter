/*
** EPITECH PROJECT, 2023
** Struct
** File description:
** Game_Context
*/

#ifndef GAME_CONTEXT_H_
    #define GAME_CONTEXT_H_

typedef struct {
    sfRenderWindow* window;
    sfClock* clock;
    level_audio* audio;
} game_context;

#endif
