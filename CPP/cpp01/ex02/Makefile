# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 14:15:36 by negambar          #+#    #+#              #
#    Updated: 2025/01/20 14:16:31 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = point

SRCS = main.cpp

CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g
OBJ = $(SRCS:%.cpp=%.o)
ARGS = $(filter-out $@,$(MAKECMDGOALS))

all: $(NAME)
$(NAME): $(OBJ)
	@echo Linking $(NAME)...
	$(CC) $(OBJ) -o $(NAME)

%.o : %.cpp
	@echo Compiling $<...
	$(CC) -o $@ -c $<
clean:
	@echo Cleaning...
	@rm -f $(OBJ)
fclean: clean
	@echo Cleaning...
	rm -f $(NAME)
crash: fclean $(NAME); make clean; clear; ./$(NAME) $(ARGS); rm -f $(NAME)
re: fclean all
.PHONY: clean fclean re all
.SILENT:
%:
	@: