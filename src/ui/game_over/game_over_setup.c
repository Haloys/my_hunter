/*
** EPITECH PROJECT, 2023
** Game_Over
** File description:
** Game_Over_Setup
*/

#include "../../../include/my.h"
#include "../ui_functions.h"
#include "../../utils/utils_functions.h"

button button_o(const char *path, float sl, sfVector2f pos, const game *fig)
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
    sfSprite_setPosition(button.sprite, (sfVector2f){((fig->win_width - 1000)
    - button_size.x * sl) / 2 + pos.x, pos.y});
    return button;
}

menu init_game_over(sfRenderWindow* window, const game *fig)
{
    menu menu;

    menu.menuButton = button_o("assets/images/game_over/play_again.png"
    , 1.40f, (sfVector2f){0, (2 * fig->win_height / 8)}, fig);
    menu.quitdefButton = button_o("assets/images/game_over/quit.png"
    , 1.40f, (sfVector2f){0, (5 * fig->win_height / 8)}, fig);
    menu.bgSprite = init_bg("assets/images/game_over/backgrnd.png"
    , fig->win_width, fig->win_height);
    return menu;
}

void cleanup_game_over(menu* menu)
{
    cleanup_button(&menu->menuButton);
    cleanup_button(&menu->quitdefButton);
    sfSprite_destroy(menu->bgSprite);
}

void render_game_over(sfRenderWindow* window, menu* menu)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->bgSprite, NULL);
    sfRenderWindow_drawSprite(window, menu->menuButton.sprite, NULL);
    sfRenderWindow_drawSprite(window, menu->quitdefButton.sprite, NULL);
    sfRenderWindow_display(window);
}
