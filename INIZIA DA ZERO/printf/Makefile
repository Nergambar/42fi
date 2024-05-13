# Name of the executable #
NAME = libftprintf.one.a

# Source files and object files #
SRC = ft_printf.c ft_print_c.c ft_print_hex.c ft_print_n.c ft_print_s.c ft_print_u.c \
	  ft_putchar.c ft_print_ptr.c ft_print_perc.c

OBJ = $(SRC:.c=.o)

# Compiler and compiler flags #
CC = gcc

RM = rm -f

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

# Targets #
$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
all: $(NAME)
re: fclean all
.PHONY: all clean fclean re
