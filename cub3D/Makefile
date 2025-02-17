# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 14:40:09 by ctuiango          #+#    #+#              #
#    Updated: 2025/02/02 14:40:11 by ctuiango         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

WAY = minilibx-linux
MINILIBX = -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm
SRC = src/main.c\
	src/events.c\
	src/set_imagens.c\
	src/init.c\
	src/raycasting.c\
	src/draw.c\
	src/draw_aux.c\
	src/close.c\

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	make -C ${WAY}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ} ${MINILIBX}
	#clear
	#echo "BY: Celmira Tuiango"

clean:
	rm -f ${OBJ}
	make clean -C ${WAY}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
