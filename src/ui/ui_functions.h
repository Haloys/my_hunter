/*
** EPITECH PROJECT, 2023
** Ui_Function
** File description:
** Ui_Function
*/

#ifndef UI_FUNCTIONS_H_
    #define UI_FUNCTIONS_H_

int evnt(const sfEvent* event, const sfVector2i* mouse, const button* button);
int process_game_over_events(sfRenderWindow* window, menu* menu);
int show_game_over(sfRenderWindow* window, const game* fig);
button button_o(const char *path, float sl, sfVector2f pos, const game *fig);
menu init_game_over(sfRenderWindow* window, const game *fig);
void cleanup_game_over(menu* menu);
void render_game_over(sfRenderWindow* window, menu* menu);
sfSound *init_audio(const char *file_path);

int refa(const sfEvent* event, const sfVector2i* mouse, const button* button);
int process_menu_events(sfRenderWindow* window, menu* menu);
int show_menu(sfRenderWindow* window, const game* fig);
button buton(const char *path, float sl, sfVector2f pos, const game *fig);
void cleanup_button(button* button);
menu init_menu(sfRenderWindow* window, const game* fig);
void cleanup_menu(menu* menu);
void render_menu(sfRenderWindow* window, menu* menu);

#endif
