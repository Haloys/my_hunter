/*
** EPITECH PROJECT, 2023
** Struct
** File description:
** Level_Audio
*/

#ifndef LEVEL_AUDIO_H_
    #define LEVEL_AUDIO_H_

typedef struct {
    sfSound* level_sounds[5];
    sfSoundBuffer* level_buffers[5];
    int current_level;
    int prev_level;
} level_audio;

#endif
