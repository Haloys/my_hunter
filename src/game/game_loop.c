/*
** EPITECH PROJECT, 2023
** Game
** File description:
** Game_Loop
*/

#include "../../include/my.h"
#include "../graphics/graphics_functions.h"
#include "game_functions.h"
#include "../events/events_functions.h"

void init_game(sfRenderWindow* win, sfClock* c, level_audio* la, game_st *st)
{
    st->context.window = win;
    st->context.clock = c;
    st->context.audio = la;
    st->state.delta_time = 0;
    st->state.current_level = calculate_level(st->fig->game.score);
    st->state.level_display_time = 0;
    sfRenderWindow_setMouseCursorVisible(win, sfFalse);
}

int process_game(game_context *context, gframe *fig, game_loop_state *state)
{
    int new_level;

    state->delta_time = sfTime_asSeconds(sfClock_restart(context->clock));
    for (int i = 0; i < fig->game.num_active_sprites; i++) {
        sprite_status(&fig->game.sprites[i], state->delta_time,
        &fig->frame, &fig->game);
    }
    handle_level(context->audio, fig->game.score);
    new_level = calculate_level(fig->game.score);
    if (new_level != state->current_level) {
        change_background(&fig->game, new_level - 1);
        state->current_level = new_level;
        state->level_display_time = 5.0f;
    }
    ren_frame(context->window, fig, state->delta_time,
    state->level_display_time);
    if (state->level_display_time > 0) {
        state->level_display_time -= state->delta_time;
    }
    return fig->game.lives <= 0 ? 1 : 0;
}

int game_loop(sfRenderWindow* win, sfClock* c, gframe *fig, level_audio* la)
{
    int result;
    game_st setup;

    setup.fig = fig;
    init_game(win, c, la, &setup);
    while (sfRenderWindow_isOpen(win)) {
        if (!handle_events(win, fig)) {
            return 0;
        }
        result = process_game(&setup.context, fig, &setup.state);
        if (result != 0) {
            return result;
        }
    }
    return 0;
}

void sprite_status(spr* my_sprite, float delta, frame *ffig, game *fig)
{
    int frame_width = ffig->total_width / ffig->num_frames;

    moving_sprite(my_sprite, delta, ffig, fig);
    if (!my_sprite->is_active && !my_sprite->is_ready_for_respawn) {
        my_sprite->is_ready_for_respawn = 1;
    }
    if (my_sprite->is_ready_for_respawn) {
        respawn_sprite(my_sprite, frame_width, fig);
    }
}
