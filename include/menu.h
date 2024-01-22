/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** Menu
*/

#ifndef STRUCT_MENU_H
    #define STRUCT_MENU_H

typedef struct {
    sfSprite* bgSprite;
    sfSprite* bgmSprite;
    button quitdefButton;
    button startButton;
    button quitButton;
    button menuButton;
    sfSprite* logoSprite;
} menu;

#endif
