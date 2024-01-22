/*
** EPITECH PROJECT, 2023
** Struct
** File description:
** Game_Config
*/

#ifndef GAME_CONFIG_H_
    #define GAME_CONFIG_H_

    #include "crosshair.h"

typedef struct {
    spr sprites[5];
    int num_active_sprites;
    int win_width;
    int win_height;
    int score;
    int lives;
    float speed;
    crosshair crosshair;
    sfSprite* background;
} game;

#endif
