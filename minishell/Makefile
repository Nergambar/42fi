# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 14:42:56 by negambar          #+#    #+#              #
#    Updated: 2024/09/09 14:55:02 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT = ./libft
SRC = main.c cmds.c libft/ft_strcmp.c

CC = cc
FLAGS = -Wall -Werror -Wextra -g -Ilibft
POST = -Llibft -lft -lreadline

OBJ = $(SRC:.c=.o)

all: $(NAME) $(LIBFT)
$(NAME): $(OBJ) $(LIBFT)
		@echo loading...
		@make -C $(LIBFT)
		ar rc $(NAME) $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(POST)
		@echo complete!
%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<
clean:
	@echo Cleaning...
	@rm -f $(OBJ)
	@make clean -C $(LIBFT)
fclean: clean
	@echo fully cleaning...
	@make fclean -C $(LIBFT)
	rm -f $(NAME)

crash: fclean $(NAME); make clean
re: fclean all
.PHONY: clean fclean re all
.SILENT: