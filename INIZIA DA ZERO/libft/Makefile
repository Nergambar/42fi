# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 16:52:41 by negambar          #+#    #+#              #
#    Updated: 2024/05/13 11:52:58 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable #
NAME = libft.one.a

# Source files and object files #
SRC = ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_bzero.c ft_putstr_fd.c ft_strlen.c \
ft_calloc.c ft_split.c \
ft_strchr.c ft_strnstr.c \
ft_isascii.c ft_strrchr.c \
ft_putchar_fd.c ft_isalpha.c

OBJ = $(SRC:.c=.o)

# Compiler and compiler flags #
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Targets #
$(NAME): $(OBJ)
	$(AR) -r $@ $?
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
all: $(NAME)
re: fclean all
.PHONY: all clean fclean re