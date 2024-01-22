/*
** EPITECH PROJECT, 2023
** Events
** File description:
** Sprite_Interaction
*/

#include "../../include/my.h"
#include "../graphics/graphics_functions.h"
#include "events_functions.h"

void respawn_sprite(spr* a_sprite, int frame_width, const game *fig)
{
    int max_y = fig->win_height - 200;

    if (rand() % 2 == 0) {
        a_sprite->position = (sfVector2f){-frame_width,
        rand() % max_y};
        a_sprite->direction = 1;
    } else {
        a_sprite->position = (sfVector2f){fig->win_width,
        rand() % max_y};
        a_sprite->direction = -1;
    }
    a_sprite->is_active = 1;
    a_sprite->is_ready_for_respawn = 0;
    a_sprite->life_decremented = 0;
    sfSprite_setPosition(a_sprite->sprite, a_sprite->position);
}

void spr_click(const sfEvent event, sfRenderWindow* win, gframe *fig)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);
    sfFloatRect sprite_bounds;

    for (int i = 0; i < fig->game.num_active_sprites; i++) {
        sprite_bounds = sfSprite_getGlobalBounds(fig->game.sprites[i].sprite);
        if (sfFloatRect_contains(&sprite_bounds, mouse_pos.x, mouse_pos.y)
            && fig->game.sprites[i].is_active) {
            fig->game.sprites[i].is_active = 0;
            fig->game.sprites[i].is_ready_for_respawn = 1;
            fig->game.score++;
            fig->game.speed += 5.0f;
            check_for_new_sprite(&fig->game, &fig->frame);
        }
    }
}
