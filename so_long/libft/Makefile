# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 16:52:41 by negambar          #+#    #+#              #
#    Updated: 2024/03/19 11:45:27 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable #
NAME = libft.a

# Source files and object files #
SRC = ft_strlcat.c ft_substr.c \
ft_atoi.c ft_strlcpy.c \
ft_bzero.c ft_calloc.c ft_memchr.c ft_strlen.c \
ft_memcmp.c ft_split.c ft_strmapi.c \
ft_memcpy.c ft_strchr.c ft_strncmp.c \
ft_memmove.c ft_strdup.c ft_strnstr.c \
ft_memset.c ft_striteri.c ft_strrchr.c \
ft_strjoin.c ft_itoa.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Compiler and compiler flags #
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Targets #
$(NAME): $(OBJ)
	$(AR) -r $@ $?
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
clean:
	rm -f $(OBJ) $(BONUS_OBJ)
fclean: clean
	rm -f $(NAME)
bonus: $(BONUS_OBJ)
	ar rc $(NAME) $(BONUS_OBJ)
	ranlib $(NAME)
all: $(NAME) bonus
re: fclean all
.PHONY: all clean fclean bonus re