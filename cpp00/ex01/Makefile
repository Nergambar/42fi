NAME = phonebookandall

SRCS = PhoneBook.cpp Contact.cpp main.cpp Set.cpp Get.cpp

CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g
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