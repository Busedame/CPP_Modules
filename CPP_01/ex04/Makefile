CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OPTIONS = -c
SRC =	main.cpp \
		Replace.cpp
NAME = replace
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32m🎉COMPILATION SUCCESS🥳\033[0m"
	@echo "\033[0;33mUsage: This program takes a file, changes every occurence of first string with the second string, and puts it into a new file (outfile).\033[0m"
	@echo "\033[0;33mUsage: Usage: ./replace <filename> <what_should_be_replaced> <replacement> \033[0m"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) && echo "\033[0;31mRemoved object files 🗑️\033[0m"

fclean: clean
	@rm -f $(NAME) && echo "\033[0;31mRemoved executable 🗑️\033[0m"

re: fclean all

.PHONY: all clean fclean re