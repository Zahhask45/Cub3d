# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 12:05:15 by jodos-sa          #+#    #+#              #
#    Updated: 2023/10/27 15:45:09 by jodos-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
LIBC	= ar rc
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -g

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
			ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
			ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			GNL/get_next_line_bonus.c GNL/get_next_line_utils_bonus.c

#get_next_line/get_next_line.c get_next_line/ft_strchrr.c get_next_line/ft_strlenn.c
OBJS =  $(SRC:.c=.o)

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJS = $(BONUS_SRC:.c=.o)

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

bonus: ${OBJS} ${BONUS_OBJS}
	${LIBC} ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(BONUS_SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_OBJS)
