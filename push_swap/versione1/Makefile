# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 15:40:15 by negambar          #+#    #+#              #
#    Updated: 2024/05/28 12:22:47 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft
PRINTF = printf

LIBFT_MAKE =  libft/Makefile
PRINTF_MAKE = printf/Makefile

SRC = main.c error.c ft_atoi_mdf.c\
lists/ft_lstnew.c lists/ft_lstadd_front.c \
lists/ft_lstsize.c lists/ft_lstlast.c lists/ft_lstadd_back.c lists/ft_lstdelone.c \
lists/ft_lstclear.c lists/ft_lstiter.c ft_isdigit.c sortings.c \
various_sort.c init.c utils.c tuttomio.c testing.c	utils2.c utils3.c \
do_move.c

CC = cc
FLAGS = -Wall -Wextra -Werror -g -Ilibft -Iprintf
LIBS = -L$(LIBFT) -L$(PRINTF) -lft -lftprintf

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_MAKE) $(PRINTF_MAKE)
	@echo Linking $(NAME)...
	$(MAKE) -C $(LIBFT)
	@echo linking libft...
	$(MAKE) -C $(PRINTF)
	@echo linking printf...
	$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(LIBS)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<
clean:
		@echo Cleaning...
		@rm -f $(OBJ)
		@make clean -C $(LIBFT)
		@echo cleaning libft...
		@make clean -C $(PRINTF)
		@echo cleaning printf...
fclean: clean
		@echo Cleaning...
		@make fclean -C $(LIBFT)
		@make fclean -C $(PRINTF)
		@rm -f $(NAME)
crash:	
		@make all
		@echo crashing the Makefile...
		@rm -f $(OBJ)
		@make clean -C $(LIBFT)
		@make clean -C $(PRINTF)
		@echo ...
		@echo $(NAME) created
		@echo Makefile crashed successfully
re: fclean all
.PHONY: clean fclean re all
.SILENT: