/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** Button
*/

#ifndef STRUCT_BUTTON_H
    #define STRUCT_BUTTON_H

typedef struct {
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f position;
    float scale;
} button;

#endif
