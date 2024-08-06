# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 12:56:03 by negambar          #+#    #+#              #
#    Updated: 2024/07/10 13:19:41 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c \
	cost.c \
	digit.c \
	do_move.c \
	initialisation.c \
	input_check.c \
	input_check_utils.c \
	position.c \
	push.c \
	rotate.c \
	rrotate.c \
	swap.c \
	stack.c \
	sort_tiny.c \
	sort.c \
	utils.c

CC = cc
FLAGS = -Wall -Wextra -Werror -g

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo Linking $(NAME)...
	$(CC) $(OBJ) -o $(NAME) $(FLAGS)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<
clean:
		@echo Cleaning...
		@rm -f $(OBJ)
fclean: clean
		@echo Cleaning...
		@rm -f $(NAME)
crash:	
		@make all
		@echo crashing the Makefile...
		@rm -f $(OBJ)
		@echo ...
		@echo $(NAME) created successfully
		@echo Makefile self-destructed
re: fclean all

.SILENT: