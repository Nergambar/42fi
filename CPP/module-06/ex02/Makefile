# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 11:27:03 by negambar          #+#    #+#              #
#    Updated: 2025/05/05 11:31:47 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Base

SRC = Base.cpp A.cpp B.cpp C.cpp main.cpp

CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)
$(NAME): $(OBJ)
	@echo Linking...
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	rm -f $(OBJ)

%.o : %.cpp
	@echo Compiling...
	$(CC) $(FLAGS) -o $@ -c $<
fclean:
	rm -f $(NAME)
crash: fclean; make; clear; ./$(NAME);rm -f $(NAME)
re: fclean all
.PHONY: fclean re all
.SILENT: