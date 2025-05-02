# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 12:49:00 by ctuiango          #+#    #+#              #
#    Updated: 2024/08/10 13:00:18 by ctuiango         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = Minitalk

CLIENT = client
SERVER = server

SRC_C = client.c\
	auxilary.c

SRC_S = server.c

OBJ_C = ${SRC_C:.c=.o}
OBJ_S = ${SRC_S:.c=.o}

RM = rm -f
CFLAGS = -Wall -Wextra -Werror
CC = cc
PRINTF = ft_printf

all: ${NAME}

${NAME}: ${CLIENT} ${SERVER}

${CLIENT}: ${OBJ_C}
	@make -C ${PRINTF}
	${CC} ${CFLAGS} -o ${CLIENT} ${OBJ_C} ${PRINTF}/libftprintf.a

${SERVER}: ${OBJ_S}
	@make -C ${PRINTF}
	${CC} ${CFLAGS} -o ${SERVER} ${OBJ_S} ${PRINTF}/libftprintf.a

git: fclean
	git add .
	git commit -m "update" 
	git push

clean:
	@make clean -C ${PRINTF}
	${RM} ${OBJ_C}
	${RM} ${OBJ_S}
	
fclean: clean
	@make fclean -C ${PRINTF}
	${RM} ${NAME}
	${RM} ${CLIENT} ${SERVER}

re: fclean all

.PHONY: all clean fclean re
	

