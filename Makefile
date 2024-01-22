##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME 	= my_hunter

RM	= rm -f

MAKE 	= make

OBJ	= $(SRC:.c=.o)

INCLUDE = -I ./include/

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

LIB = -L ./lib/my/ -lmy

SRC =	src/main.c				\
	src/common/cleanup.c			\
	src/common/state_control.c		\
	src/events/events_handling.c		\
	src/events/sprite_interaction.c		\
	src/game/game_control.c			\
	src/game/game_loop.c			\
	src/game/game_level.c			\
	src/game/game_level_bg.c		\
	src/graphics/render.c			\
	src/graphics/crosshair.c		\
	src/graphics/sprite.c			\
	src/graphics/display_ui.c		\
	src/ui/game_over/game_over_control.c	\
	src/ui/game_over/game_over_setup.c	\
	src/ui/menu/menu_control.c		\
	src/ui/menu/menu_setup.c		\
	src/utils/background.c			\
	src/utils/window.c

all: $(NAME)

$(NAME):
	cd lib/my/ && $(MAKE)
	gcc $(SRC) -o $(NAME) $(INCLUDE) $(CSFML) $(LIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
