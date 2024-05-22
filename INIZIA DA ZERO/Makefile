# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 15:40:15 by negambar          #+#    #+#              #
#    Updated: 2024/05/20 12:37:38 by negambar         ###   ########.fr        #
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
various_sort.c init.c utils.c tuttomio.c proviamoci_dai.c test.c\

CC = cc
FLAGS = -Wall -Wextra -Werror -g -Ilibft -Iprintf
LIBS = -L$(LIBFT) -L$(PRINTF) -lft -lftprintf

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_MAKE) $(PRINTF_MAKE)
	@echo Linking... $(NAME)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(PRINTF)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(LIBS)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<
clean:
		@echo Cleaning...
		@rm -f $(OBJ)
		@make clean -C $(LIBFT)
		@make clean -C $(PRINTF)
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
re: fclean all
.PHONY: clean fclean re all
.SILENT: