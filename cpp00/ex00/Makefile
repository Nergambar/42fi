# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 14:07:34 by negambar          #+#    #+#              #
#    Updated: 2025/01/13 14:27:39 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = megaphone.cpp

CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
OBJ = $(SRCS:%.cpp=%.o)

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
	rm -f $(OBJ)
crash: fclean $(NAME); make clean
re: fclean all
.PHONY: clean fclean re all
.SILENT: