# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctuiango <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 08:17:34 by ctuiango          #+#    #+#              #
#    Updated: 2025/03/28 08:17:38 by ctuiango         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

OBJ = ${SRC:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re

