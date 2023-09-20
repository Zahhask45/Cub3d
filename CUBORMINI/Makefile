# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 14:01:01 by jodos-sa          #+#    #+#              #
#    Updated: 2023/09/20 15:22:03 by brumarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

SRC_PATH	= ./src/
OBJ_PATH	= ./obj/



SOURCES		=	main.c \
				utils.c \
				map_valid/create_map.c



SRC	= $(addprefix $(SRC_PATH), $(SOURCES))
OBJS			= $(SOURCES:.c=.o)
OBJ		= $(addprefix $(OBJ_PATH), $(OBJS))


all: $(MLX) $(LIB) $(NAME)

$(MLX):
	@printf "Making MiniLibX..."
	@make -sC $(MLX_PATH)

$(LIB):
	@printf "Making LIBFT..."
	@make -sC $(LIB_PATH)

$(NAME): $(OBJ)
	@printf "\033[2K\r$(_GREEN) All files compiled into '$(OBJ_PATH)'. $(_END)\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIB) $(INCLUDE) -lXext -lX11 -lm
	@printf "\033[2K\r$(_GREEN) Executable '$(NAME)' created. $(_END)\n"

$(OBJ):		| $(OBJ_PATH)


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
				@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END) "
				@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_PATH):
				@mkdir $(OBJ_PATH) \
				@mkdir -p $@/map_valid/

clean:
	@$(RM) $(OBJ_PATH) $(OBJ_PATH_BONUS)
	@make -sC $(LIB_PATH) clean
	@make -sC $(MLX_PATH) clean
	@printf "\033[2K\r$(_RED) '"$(OBJ_PATH)"' has been deleted. $(_END)\n"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make -sC $(LIB_PATH) fclean
	@printf "\033[2K\r$(_RED) '"$(NAME)"' has been deleted. $(_END)\n"

re: fclean all