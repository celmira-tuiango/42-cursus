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
src/validate_one.c\
      	src/validate_two.c\
      	src/validate_three.c\
      	src/validate_four.c\
	src/get_map/ft_split.c\
	src/get_map/ft_split_aux.c\
	src/get_map/get_map.c\
	src/get_map/closed_map.c\
	src/get_map/get_nextline.c\
	src/get_map/valid_two.c\
	src/get_map/aux_validate_one.c\
	src/get_map/aux_validate_four.c\
	src/get_map/replace_one.c\
	src/aux_func/ft_sscanf.c\
	src/aux_func/ft_aux_sscanf.c\
	src/aux_func/ft_strlen.c\
	src/aux_func/ft_strcmp.c\
	src/aux_func/ft_strncmp.c\
	src/aux_func/ft_strdup.c\
	src/aux_func/ft_strcat.c\
	src/aux_func/ft_isdigit.c\
	src/aux_func/ft_isspace.c\
	src/aux_func/ft_memset.c\
	src/aux_func/ft_strcpy.c\
	src/aux_func/ft_atoi.c\
	src/events.c\
	src/set_imagens.c\
	src/init.c\
	src/raycasting.c\
	src/distance_angle.c\
	src/draw_background.c\
	src/close.c\

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	make -C ${WAY}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ} ${MINILIBX}
	#clear
	#echo "BY: Team CC"

clean:
	rm -f ${OBJ}
	make clean -C ${WAY}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
