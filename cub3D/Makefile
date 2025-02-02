NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

WAY = minilibx-linux
MINILIBX = -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm
SRC = src/main.c\
	src/player.c\

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
