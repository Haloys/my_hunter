/*
** EPITECH PROJECT, 2023
** Common
** File description:
** Cleanup
*/

#include "../../include/my.h"
#include "common_functions.h"

void cleanup(spr* my_sprite, sfClock* clock)
{
    if (my_sprite) {
        if (my_sprite->sprite)
            sfSprite_destroy(my_sprite->sprite);
        if (my_sprite->texture)
            sfTexture_destroy(my_sprite->texture);
        free(my_sprite);
    }
    if (clock)
        sfClock_destroy(clock);
}
