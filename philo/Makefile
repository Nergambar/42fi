# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 12:31:57 by negambar          #+#    #+#              #
#    Updated: 2024/07/23 12:49:18 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

GCC = gcc -Wall -Wextra -Werror -g3 -pthread

SRC =	main.c \
		control.c \
		init/start.c \
		init/timer.c \
		init/more.c \
		init/status.c \
		extra/extra.c \
		extra/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
		@echo Linking... $(NAME)
		$(GCC) $(OBJ) -o $(NAME)
%.o : %.c
	@echo Compiling $<...
	$(GCC) -o $@ -c $<
clean:
		@echo Cleaning...
		@rm -f $(OBJ)
fclean: clean
		@echo Cleaning...
		rm -f $(NAME)
crash: fclean $(NAME); make clean
re: fclean all
.PHONY: clean fclean re all
.SILENT: