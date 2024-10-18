# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 12:06:55 by ctuiango          #+#    #+#              #
#    Updated: 2024/09/13 12:25:01 by ctuiango         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

WAY = minilibx-linux
MINILIBX = -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm
SRC = src/main.c\
		src/get_map.c\
		src/aux_func1.c\
		src/ft_close.c\
		src/ft_split.c\
		src/ft_split_aux.c\
		src/get_nextline.c\
		src/ft_strlen.c\
		src/render_map.c\
		src/move_p.c\
		src/validations_one.c\
		src/validation_two.c\
		src/validation_three.c\
		src/validation_four.c\
		src/set_images.c\
		ft_printf/auxilary_func.c\
		ft_printf/ft_cel.c\
		ft_printf/ft_printf.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	make -C ${WAY}
	${CC} ${CFLAGS} -o ${NAME} ${OBJ} ${MINILIBX}
	clear
	echo "BY: Celmira Tuiango"

clean:
	rm -f ${OBJ}
	make clean -C ${WAY}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
