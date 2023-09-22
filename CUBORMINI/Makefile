# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 14:01:01 by jodos-sa          #+#    #+#              #
#    Updated: 2023/09/22 16:57:15 by jodos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_END		=	\e[0m
_BOLD		=	\e[1m
_UNDER		=	\e[4m
_REV		=	\e[7m


_GREY		=	\e[1;30m
_RED		=	\e[1;31m
_GREEN		=	\e[1;32m
_YELLOW		=	\e[1;33m
_BLUE		=	\e[1;34m
_PURPLE		=	\e[1;35m
_CYAN		=	\e[1;36m
_WHITE		=	\e[1;37m



CC			= cc
CFLAGS		= -g -pthread -Wall -Werror -Wextra


RM			= rm -rf


NAME		= cub


MLX_PATH	= ./mlx/minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

LIB_PATH	= ./libft/
LIB_NAME	= libft.a
LIB			= $(LIB_PATH)$(LIB_NAME)


INCLUDE		=	-I ./inc/\
				-I ./mlx/minilibx-linux/\
				-I ./libft/

SRC_DIR		=	./src/
OBJ_DIR		=	./obj/



WIN_DIR		=	window/

WINDOW		=	window.c \
				win_utils.c \
				init_minimap.c \

MAP_DIR		=	map_valid/

MAP			=	create_map.c \
				init_textures.c \

SRC			=	$(addprefix $(SRC_DIR), $(SOURCES))
WIN_SRC		=	$(addprefix $(WIN_DIR), $(WINDOW))
MAP_SRC		=	$(addprefix $(MAP_DIR), $(MAP))

SOURCES		=	$(WIN_SRC) \
				$(MAP_SRC) \
				main.c \
				utils.c \


OBJS		=	$(SOURCES:.c=.o)
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJS))


all: $(MLX) $(LIB) $(NAME)

$(MLX):
	printf "Making MiniLibX..."
	make -sC $(MLX_PATH)

$(LIB):
	printf "Making LIBFT..."
	make -sC $(LIB_PATH)

$(NAME): $(OBJ)
	printf "\033[2K\r$(_GREEN) All files compiled into '$(OBJ_DIR)'. $(_END)\n"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIB) $(INCLUDE) -lXext -lX11 -lm
	printf "\033[2K\r$(_GREEN) Executable '$(NAME)' created. $(_END)\n"

$(OBJ):		| $(OBJ_DIR)


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				printf "\033[2K\r $(_YELLOW)Compiling $< $(_END) "
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)
				mkdir -p $@/window
				mkdir -p $@/map_valid

clean:
	$(RM) $(OBJ_DIR) $(OBJ_PATH_BONUS)
	make -sC $(LIB_PATH) clean
	make -sC $(MLX_PATH) clean
	printf "\033[2K\r$(_RED) '"$(OBJ_DIR)"' has been deleted. $(_END)\n"

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make -sC $(LIB_PATH) fclean
	printf "\033[2K\r$(_RED) '"$(NAME)"' has been deleted. $(_END)\n"

re: fclean all

.SILENT: