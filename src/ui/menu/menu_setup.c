/*
** EPITECH PROJECT, 2023
** Menu
** File description:
** Menu_Setup
*/

#include "../../../include/my.h"
#include "../ui_functions.h"
#include "../../utils/utils_functions.h"

button buton(const char *path, float sl, sfVector2f pos, const game *fig)
{
    button button;
    sfVector2u button_size;

    button.texture = sfTexture_createFromFile(path, NULL);
    button.sprite = sfSprite_create();
    sfSprite_setTexture(button.sprite, button.texture, sfTrue);
    button_size = sfTexture_getSize(button.texture);
    button.scale = sl;
    sfSprite_setScale(button.sprite, (sfVector2f){sl, sl});
    button.position = pos;
    sfSprite_setPosition(button.sprite, (sfVector2f)
    {((fig->win_width - 1000) - button_size.x * sl) / 2 + pos.x, pos.y});
    return button;
}

void cleanup_button(button* button)
{
    if (button->sprite) {
        sfSprite_destroy(button->sprite);
    }
    if (button->texture) {
        sfTexture_destroy(button->texture);
    }
}

menu init_menu(sfRenderWindow* window, const game* fig)
{
    menu menu;
    sfTexture* logoTex = sfTexture_createFromFile
    ("assets/images/menu/logo.png", NULL);
    sfVector2u logoSize = sfTexture_getSize(logoTex);
    float logoScale = 0.80f;

    menu.startButton = buton("assets/images/menu/start.png"
    , 0.65f, (sfVector2f){0, (3 * fig->win_height / 8)}, fig);
    menu.quitButton = buton("assets/images/menu/quit.png"
    , 0.65f, (sfVector2f){0, (5 * fig->win_height / 8)}, fig);
    menu.logoSprite = sfSprite_create();
    sfSprite_setTexture(menu.logoSprite, logoTex, sfTrue);
    sfSprite_setScale(menu.logoSprite, (sfVector2f){logoScale, logoScale});
    sfSprite_setPosition(menu.logoSprite, (sfVector2f)
    {(fig->win_width - logoSize.x * logoScale) / 2, 10});
    menu.bgSprite = init_bg("assets/images/menu/backgrnd.png"
    , fig->win_width, fig->win_height);
    return menu;
}

void cleanup_menu(menu* menu)
{
    cleanup_button(&menu->startButton);
    cleanup_button(&menu->quitButton);
    sfSprite_destroy(menu->logoSprite);
    sfSprite_destroy(menu->bgSprite);
}

void render_menu(sfRenderWindow* window, menu* menu)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->bgSprite, NULL);
    sfRenderWindow_drawSprite(window, menu->logoSprite, NULL);
    sfRenderWindow_drawSprite(window, menu->startButton.sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->quitButton.sprite, NULL);
    sfRenderWindow_display(window);
}
