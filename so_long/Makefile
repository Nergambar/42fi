# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 10:47:43 by negambar          #+#    #+#              #
#    Updated: 2024/03/22 16:33:49 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = ./libft 
SRC = screen.c image.c map_mtx.c map.c clearmtx.c get_next_line.c moves.c \
	floodfill.c

CC = cc
FLAGS = -Wall -Wextra -Werror -g -Ilibft
MINILBX = -Lminilibx-linux -lmlx -Llibft -lft -lXext -lX11

OBJ = $(SRC:.c=.o)
all: $(NAME) $(LIBFT)
$(NAME): $(OBJ) $(LIBFT)
		@echo Linking... $(NAME)
		@make -C $(LIBFT)
		$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(MINILBX)
%.o : %.c
	@echo Compiling $<...
	$(CC) $(FLAGS) -o $@ -c $<
clean:
		@echo Cleaning...
		@rm -f $(OBJ)
		@make clean -C $(LIBFT)
fclean: clean
		@echo Cleaning...
		@make fclean -C $(LIBFT)
		rm -f $(NAME)
crash: fclean $(NAME); make clean
re: fclean all
.PHONY: clean fclean re all