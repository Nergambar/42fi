# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 10:47:43 by negambar          #+#    #+#              #
#    Updated: 2024/04/22 15:32:00 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = ./libft
PRINTF = ./printf

SRC = utils_map/map_mtx.c utils_map/map.c \
	utils_map/clearmtx.c utils_map/mtxdup.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c \
	main.c  moves/moves.c moves/moves_utils.c \
	images/image.c images/floodfill.c \
	error.c screen_utils.c error_free.c 

CC = cc
FLAGS = -Wall -Wextra -Werror -g -Ilibft -Iprintf
MINILBX = -Lminilibx-linux -lmlx -Llibft -Lprintf -lftprintf -lft -lXext -lX11

OBJ = $(SRC:.c=.o)

all: $(NAME) $(LIBFT) $(PRINTF)
$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
		@echo Linking... $(NAME)
		@make -C $(LIBFT)
		@make -C $(PRINTF)
		ar rc $(NAME) $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(MINILBX)
%.o : %.c
	@echo Compiling $<...
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
		rm -f $(NAME)
crash: fclean $(NAME); make clean
re: fclean all
.PHONY: clean fclean re all