/*
** EPITECH PROJECT, 2023
** Graphics_Functions
** File description:
** Graphics_Functions
*/

#ifndef GRAPHICS_FUNCTIONS_H_
    #define GRAPHICS_FUNCTIONS_H_

void ren_frame(sfRenderWindow* win, gframe *fig, float delta, float lvl_time);
void render_sp(sfRenderWindow* win, spr* spr, float delta, const frame *ffig);
void display_lives(sfRenderWindow* window, const game *fig);
void display_score(sfRenderWindow* window, int score);
void display_level(sfRenderWindow* window, int score, const game *fig);
spr* initialize_sprite(const char *path, const frame *ffig, const game *fig);
void animate_sprite(spr* a_sprite, float delta, float dur, const frame *ffig);
void moving_sprite(spr* a_sprite, float delta, const frame *ffig, game *fig);
void check_for_new_sprite(game *fig, frame *frame_config);
crosshair initialize_crosshair(const char *texturePath);
void update_and_draw_crosshair(sfRenderWindow* window, crosshair* crosshair);
void display_level_center(sfRenderWindow* window, int level, const game *fig);

#endif
