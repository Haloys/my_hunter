/*
** EPITECH PROJECT, 2023
** Graphics
** File description:
** Display_Ui
*/

#include "../../include/my.h"
#include "graphics_functions.h"

void display_level_center(sfRenderWindow* window, int level, const game *fig)
{
    char level_str[50];
    sfText* level_text = sfText_create();
    sfFont* font = sfFont_createFromFile("assets/fonts/Font.ttf");
    char display_str[60] = "Level: ";
    sfFloatRect textRect;

    my_long_to_string((long)level, level_str);
    my_strcat(display_str, level_str);
    sfText_setString(level_text, display_str);
    sfText_setFont(level_text, font);
    sfText_setCharacterSize(level_text, 75);
    sfText_setColor(level_text, sfWhite);
    textRect = sfText_getLocalBounds(level_text);
    sfText_setOrigin(level_text, (sfVector2f){(textRect.width / 2 - (70)),
    textRect.height / 4});
    sfText_setPosition(level_text, (sfVector2f){(fig->win_width / 2 - (70)),
    fig->win_height / 4});
    sfRenderWindow_drawText(window, level_text, NULL);
    sfText_destroy(level_text);
    sfFont_destroy(font);
}
