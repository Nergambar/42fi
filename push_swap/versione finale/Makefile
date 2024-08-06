# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 12:56:03 by negambar          #+#    #+#              #
#    Updated: 2024/07/16 11:33:23 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c \
	cost.c \
	do_move.c \
	initialization.c \
	input_check.c \
	input_check_utils.c \
	position.c \
	push.c \
	rotate.c \
	reverse_rotate.c \
	swap.c \
	stack.c \
	sort_tiny.c \
	sort.c \
	utils.c \
	init_utils.c \
	ft_split.c

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