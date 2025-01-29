NAME = Harl

SRCS = main.cpp Harl.cpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME):
	$(CC) $(SRCS) $(FLAGS) -o $(NAME)

clean:
	@echo "*cocks shotgun* hasta la vista, Gromit"
	@echo "\noh i forgot to put ammos in this... (no object files to delete)"

fclean:
	@echo "hasta la vista, Gromit *blows up the notre dame*"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: