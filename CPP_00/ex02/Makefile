CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OPTIONS = -c
SRC =	Account.cpp \
		tests.cpp
NAME = account
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32m🎉COMPILATION SUCCESS🥳\033[0m"
	@echo "\033[0;33mUsage: Run ./account and see if the output is identical to the log-file.\033[0m"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) && echo "\033[0;31mRemoved object files 🗑️\033[0m"

fclean: clean
	@rm -f $(NAME) && echo "\033[0;31mRemoved executable 🗑️\033[0m"

re: fclean all

.PHONY: all clean fclean re