# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: negambar <negambar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 16:23:39 by negambar          #+#    #+#              #
#    Updated: 2025/01/20 16:14:25 by negambar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME2 = client

SRC = printf/ft_printf.c printf/ft_print_c.c printf/ft_print_hex.c printf/ft_print_n.c printf/ft_print_s.c printf/ft_print_u.c \
		printf/ft_putchar.c printf/ft_print_ptr.c printf/ft_print_perc.c ft_atoi.c 
SERVER = server.c
CLIENT = client.c

OBJ = $(SRC:.c=.o)
NOBJ = $(SERVER:.c=.o) $(CLIENT:.c=.o)

CC = cc

RM = rm -f

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror -I./printf

# Targets #
all: $(NAME) $(NAME2) $(PRINTF)

$(NAME): $(OBJ) server.o
	$(CC) $(CFLAGS) server.o $(OBJ) -o server
$(NAME2): $(OBJ) client.o
	$(CC) $(CFLAGS) client.o $(OBJ) -o client

clean:
	$(RM) $(OBJ) $(NOBJ)
fclean: clean
	$(RM) server client

re: fclean all
#.PHONY: all clean fclean re