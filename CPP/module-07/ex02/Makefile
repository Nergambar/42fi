# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 10:43:09 by negambar          #+#    #+#              #
#    Updated: 2025/05/09 09:49:02 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = array

SRC = main.cpp
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)
$(NAME) : $(OBJ)
	@echo Linking...
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	@echo Compiling...
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@echo Cleaning...
	rm -f $(OBJ)

fclean: clean;
	@sleep 1
	@echo Removing extra stuff..
	rm -f $(NAME)

re: fclean all
.PHONY: fclean re all
.SILENT: