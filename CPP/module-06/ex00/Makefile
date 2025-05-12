# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 13:23:23 by negambar          #+#    #+#              #
#    Updated: 2025/05/03 14:14:56 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Converter

SRC = ScalarConverter.cpp
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
crash: fclean $(NAME); make; clear; ./$(NAME); rm -f $(NAME)
re: fclean all
.PHONY: fclean re all
.SILENT: