/*
** EPITECH PROJECT, 2023
** Graphics
** File description:
** Render
*/

#include "../../include/my.h"
#include "graphics_functions.h"
#include "../game/game_functions.h"

void ren_frame(sfRenderWindow* win, gframe *fig, float delta, float lvl_time)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, fig->game.background, NULL);
    for (int i = 0; i < fig->game.num_active_sprites; i++) {
        render_sp(win, &fig->game.sprites[i], delta, &fig->frame);
    }
    update_and_draw_crosshair(win, &fig->game.crosshair);
    display_score(win, fig->game.score);
    display_lives(win, &fig->game);
    if (lvl_time > 0) {
        display_level_center(win, calculate_level(fig->game.score),
        &fig->game);
    } else {
        display_level(win, fig->game.score, &fig->game);
    }
    sfRenderWindow_display(win);
}

void render_sp(sfRenderWindow* win, spr* spr, float delta, const frame *ffig)
{
    int frame_width = ffig->total_width / ffig->num_frames;
    int frame_height = ffig->total_height;

    if (spr->is_active) {
        animate_sprite(spr, delta, 0.1, ffig);
        sfRenderWindow_drawSprite(win, spr->sprite, NULL);
    }
}

void display_lives(sfRenderWindow* window, const game *fig)
{
    char lives_str[50];
    sfText* lives_text = sfText_create();
    sfFont* font = sfFont_createFromFile("assets/fonts/Font.ttf");
    char display_str[60] = "Lives: ";

    my_long_to_string((long)fig->lives, lives_str);
    my_strcat(display_str, lives_str);
    sfText_setString(lives_text, display_str);
    sfText_setFont(lives_text, font);
    sfText_setCharacterSize(lives_text, 24);
    sfText_setColor(lives_text, sfWhite);
    sfText_setPosition(lives_text, (sfVector2f){fig->win_width - 110, 10});
    sfRenderWindow_drawText(window, lives_text, NULL);
    sfText_destroy(lives_text);
    sfFont_destroy(font);
}

void display_score(sfRenderWindow* window, int score)
{
    char score_str[50];
    sfText* score_text = sfText_create();
    sfFont* font = sfFont_createFromFile("assets/fonts/Font.ttf");
    char display_str[60] = "Score: ";

    my_long_to_string((long)score, score_str);
    my_strcat(display_str, score_str);
    sfText_setString(score_text, display_str);
    sfText_setFont(score_text, font);
    sfText_setCharacterSize(score_text, 24);
    sfText_setColor(score_text, sfWhite);
    sfText_setPosition(score_text, (sfVector2f){10, 10});
    sfRenderWindow_drawText(window, score_text, NULL);
    sfText_destroy(score_text);
    sfFont_destroy(font);
}

void display_level(sfRenderWindow* window, int score, const game *fig)
{
    char level_str[50];
    sfText* level_text = sfText_create();
    sfFont* font = sfFont_createFromFile("assets/fonts/Font.ttf");
    char display_str[60] = "Level: ";
    int level = calculate_level(score);

    my_long_to_string((long)level, level_str);
    my_strcat(display_str, level_str);
    sfText_setString(level_text, display_str);
    sfText_setFont(level_text, font);
    sfText_setCharacterSize(level_text, 24);
    sfText_setColor(level_text, sfWhite);
    sfText_setPosition(level_text, (sfVector2f){(fig->win_width / 2 - (70)),
    10});
    sfRenderWindow_drawText(window, level_text, NULL);
    sfText_destroy(level_text);
    sfFont_destroy(font);
}
