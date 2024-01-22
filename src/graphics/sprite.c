/*
** EPITECH PROJECT, 2023
** Graphics
** File description:
** Sprite
*/

#include "../../include/my.h"
#include "graphics_functions.h"

spr* initialize_sprite(const char *path, const frame *ffig, const game *fig)
{
    int frame_width = ffig->total_width / ffig->num_frames;
    int frame_height = ffig->total_height;
    spr* my_sprite = malloc(sizeof(spr));
    int max_y = fig->win_height - 200;

    my_sprite->texture = sfTexture_createFromFile(path, NULL);
    my_sprite->sprite = sfSprite_create();
    sfSprite_setTexture(my_sprite->sprite, my_sprite->texture, sfTrue);
    sfSprite_setTextureRect(my_sprite->sprite,
    (sfIntRect){0, 0, frame_width, frame_height});
    sfSprite_setScale(my_sprite->sprite, (sfVector2f){0.40f, 0.40f});
    my_sprite->elapsed_time = 0.0f;
    my_sprite->is_active = 1;
    my_sprite->is_ready_for_respawn = 0;
    my_sprite->life_decremented = 0;
    my_sprite->position = (rand() % 2 == 0) ? (sfVector2f) {-frame_width,
    rand() % max_y} : (sfVector2f){fig->win_width, rand() % max_y};
    my_sprite->direction = (my_sprite->position.x < 0) ? 1 : -1;
    sfSprite_setPosition(my_sprite->sprite, my_sprite->position);
    return my_sprite;
}

void animate_sprite(spr* a_sprite, float delta, float dur, const frame *ffig)
{
    static int cur_frame = 0;
    int frame_width = ffig->total_width / ffig->num_frames;
    int frame_height = ffig->total_height;
    sfIntRect new_rect;

    a_sprite->elapsed_time += delta;
    if (a_sprite->elapsed_time >= dur) {
        cur_frame = (cur_frame + 1) % ffig->num_frames;
        new_rect = (sfIntRect){cur_frame * frame_width,
        0, frame_width, frame_height};
        sfSprite_setTextureRect(a_sprite->sprite, new_rect);
        a_sprite->elapsed_time = 0;
    }
}

void moving_sprite(spr* a_sprite, float delta, const frame *ffig, game *fig)
{
    int frame_width = ffig->total_width / ffig->num_frames;

    a_sprite->position.x += fig->speed * delta * a_sprite->direction;
    if ((a_sprite->position.x > fig->win_width ||
        a_sprite->position.x < -frame_width)
        && !a_sprite->life_decremented) {
        fig->lives--;
        a_sprite->life_decremented = 1;
    }
    if (a_sprite->position.x > fig->win_width ||
        a_sprite->position.x < -frame_width) {
        a_sprite->is_ready_for_respawn = 1;
    }
    sfSprite_setPosition(a_sprite->sprite, a_sprite->position);
}

void check_for_new_sprite(game *fig, frame *frame_config)
{
    const int cur_score = 30;
    int target_num_sprites = fig->score / cur_score + 1;

    if (target_num_sprites > 5) {
        target_num_sprites = 5;
    }
    while (fig->num_active_sprites < target_num_sprites) {
        fig->sprites[fig->num_active_sprites] = *initialize_sprite(
            "assets/images/sprite/monster.png", frame_config, fig);
        fig->num_active_sprites++;
    }
}
