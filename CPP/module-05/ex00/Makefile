NAME =  bureaucrat

SRCS = Bureaucrat.cpp main.cpp
CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g
OBJ = $(SRCS:%.cpp=%.o)

all: $(NAME)
$(NAME): $(OBJ)
	@echo Linking...
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	rm -f $(OBJ)

%.o : %.cpp
	@echo Compiling $<...
	$(CC) $(FLAGS) -o $@ -c $<
fclean:
	rm -f $(NAME)
crash: fclean $(NAME); make; clear; ./$(NAME); rm -f $(NAME)
re: fclean all
.PHONY: fclean re all
.SILENT: