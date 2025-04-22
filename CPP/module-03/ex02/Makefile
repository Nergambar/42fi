# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 11:23:04 by negambar          #+#    #+#              #
#    Updated: 2025/02/20 12:26:33 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FragTrap
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
OBJ = $(SRCS:%.cpp=%.o)

all: $(NAME)
$(NAME): $(OBJ)
	@echo Linking...
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	@echo Compiling $<...
	$(CC) $(FLAGS) -o $@ -c $<
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
crash: fclean $(NAME); make clean; clear; ./$(NAME); rm -f $(NAME)
re: fclean all
.PHONY: clean fclean re all
.SILENT: