# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 16:12:22 by negambar          #+#    #+#              #
#    Updated: 2025/03/29 10:00:59 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT = ./libft/libft.a


SRC = src/main.c \
	src/parsing/parsing.c src/parsing/parsing2.c src/parsing/parsing3.c src/parsing/parsing4.c src/parsing/parsing_utils.c \
	src/parsing/parsing_utils2.c src/parsing/parsing_utils3.c src/parsing/parsing_utils4.c\
	src/parsing/parsing_walls.c src/parsing/parsing_walls2.c src/parsing/parsing_walls3.c \
	src/utils/utils.c src/utils/utils2.c src/utils/utils3.c src/utils/gnl.c \
	src/init/init.c src/init/init2.c \
	src/controls/controls.c src/controls/control_helpers.c \
	src/rendering/rendering.c src/rendering/rendering_utils.c src/rendering/rendering_utils2.c \
	src/rendering/rendering_utils3.c src/rendering/rendering_utils4.c \
	src/free.c

OBJ = $(SRC:.c=.o) 
CC = cc

FLAGS = -Wall -Wextra -Werror -g

MINILBX = -Lminilibx-linux -lmlx -lXext -lX11 -lm
 
all: $(NAME) $(LIBFT)

minilibx:
	@$(MAKE) -C minilibx-linux

%.o : %.c
	@echo Compiling...
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): minilibx $(OBJ)
		@echo Linking... $(NAME)
		@make -C libft
		$(CC) $(OBJ) $(FLAGS) $(MINILBX) -o $(NAME) $(LIBFT)

clean:
		@echo Cleaning...
		@rm -f $(OBJ)
		@make clean -C libft

fclean: clean
		@echo Cleaning...
		rm -f libft/libft.a
		rm -f $(NAME)

crash: fclean $(NAME); make clean

re: fclean all
.PHONY: clean fclean re all
.SILENT: