/*
** EPITECH PROJECT, 2023
** Graphic
** File description:
** Crosshair
*/

#include "../../include/my.h"
#include "graphics_functions.h"

crosshair initialize_crosshair(const char *texturePath)
{
    crosshair crosshair;
    sfVector2u textureSize;

    crosshair.texture = sfTexture_createFromFile(texturePath, NULL);
    crosshair.sprite = sfSprite_create();
    sfSprite_setTexture(crosshair.sprite, crosshair.texture, sfTrue);
    textureSize = sfTexture_getSize(crosshair.texture);
    sfSprite_setOrigin(crosshair.sprite, (sfVector2f)
    {textureSize.x / 2.0f, textureSize.y / 2.0f});
    sfSprite_setScale(crosshair.sprite, (sfVector2f){5.00f, 5.00f});
    return crosshair;
}

void update_and_draw_crosshair(sfRenderWindow* window, crosshair* crosshair)
{
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(window);

    sfSprite_setPosition(crosshair->sprite, (sfVector2f)
    {mousePosition.x, mousePosition.y});
    sfRenderWindow_drawSprite(window, crosshair->sprite, NULL);
}
