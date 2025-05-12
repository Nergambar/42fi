# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 10:43:09 by negambar          #+#    #+#              #
#    Updated: 2025/05/06 10:46:33 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = template

SRC = main.cpp
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)
$(NAME) : $(OBJ)
	@echo Linking...
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	rm -f $(OBJ)

%.o : %.cpp
	@echo Compiling...
	$(CC) $(FLAGS) -o $@ -c $<
fclean:
	rm -f $(NAME)
re: fclean all
.PHONY: fclean re all
.SILENT: