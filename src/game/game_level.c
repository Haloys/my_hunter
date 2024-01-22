/*
** EPITECH PROJECT, 2023
** Game
** File description:
** Game_Level_Audio
*/

#include "../../include/my.h"
#include "game_functions.h"

const char *file_paths[5] = {
    "assets/audio/level1.ogg",
    "assets/audio/level2.ogg",
    "assets/audio/level3.ogg",
    "assets/audio/level4.ogg",
    "assets/audio/level5.ogg"
};

int calculate_level(int score)
{
    return (score / 30) + 1;
}

level_audio init_level_audio(void)
{
    level_audio la;

    for (int i = 0; i < 5; i++) {
        la.level_buffers[i] = sfSoundBuffer_createFromFile(file_paths[i]);
        la.level_sounds[i] = sfSound_create();
        sfSound_setBuffer(la.level_sounds[i], la.level_buffers[i]);
    }
    la.current_level = 1;
    la.prev_level = 0;
    return la;
}

void cleanup_level_audio(level_audio* la)
{
    for (int i = 0; i < 5; i++) {
        sfSound_destroy(la->level_sounds[i]);
        sfSoundBuffer_destroy(la->level_buffers[i]);
    }
}

void handle_level(level_audio* la, int score)
{
    la->current_level = calculate_level(score);
    if (la->current_level != la->prev_level) {
        if (la->prev_level - 1 < 5) {
            sfSound_stop(la->level_sounds[la->prev_level - 1]);
        }
        if (la->current_level - 1 < 5) {
            sfSound_play(la->level_sounds[la->current_level - 1]);
        }
        la->prev_level = la->current_level;
    }
}
