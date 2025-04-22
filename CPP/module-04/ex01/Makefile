# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 11:23:04 by negambar          #+#    #+#              #
#    Updated: 2025/03/07 12:04:57 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Brains
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g
OBJ = $(SRCS:%.cpp=%.o)

all: $(NAME)
$(NAME): $(OBJ)
	@echo Linking...
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	rm -f $(OBJ)

%.o : %.cpp
	@echo Compiling $<...
	$(CC) $(FLAGS) -o $@ -c $<
fclean:
	rm -f $(NAME)
crash: fclean $(NAME); make; clear; ./$(NAME); rm -f $(NAME)
re: fclean all
.PHONY: fclean re all
.SILENT: