/*
** EPITECH PROJECT, 2023
** Utils
** File description:
** Background
*/

#include "../../include/my.h"
#include "utils_functions.h"

sfSprite *init_bg(const char *filepath, int win_width, int win_height)
{
    sfTexture* backgroundTexture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *backgroundSprite = sfSprite_create();
    sfVector2u textureSize = sfTexture_getSize(backgroundTexture);
    sfVector2f scale;

    sfSprite_setTexture(backgroundSprite, backgroundTexture, sfTrue);
    scale.x = (float)win_width / textureSize.x;
    scale.y = (float)win_height / textureSize.y;
    sfSprite_setScale(backgroundSprite, scale);
    return backgroundSprite;
}
