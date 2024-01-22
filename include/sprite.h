/*
** EPITECH PROJECT, 2023
** Struct
** File description:
** Sprite
*/

#ifndef SPRITE_H_
    #define SPRITE_H_

typedef struct {
    sfSprite* sprite;
    sfTexture* texture;
    float elapsed_time;
    sfVector2f position;
    int is_active;
    int is_ready_for_respawn;
    int direction;
    int life_decremented;
} spr;

#endif
