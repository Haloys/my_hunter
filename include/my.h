/*
** EPITECH PROJECT, 2023
** Main Header
** File description:
** Lib principale
*/

#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "sprite.h"
#include "button.h"
#include "menu.h"
#include "game_config.h"
#include "frame_config.h"
#include "game_frame_config.h"
#include "crosshair.h"
#include "level_audio.h"
#include "game_context.h"
#include "game_loop_state.h"
#include "game_setup.h"

#ifndef MY_H_
    #define MY_H_

void my_long_to_string(long num, char *str);
int mini_printf(const char *format, ...);
int my_putchar(char c);
int my_put_nbr(int number_put);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strcmp(const char *str1, const char *str2);
int my_getnbr(char const *str);
void reverse_string(char *str);

#endif
