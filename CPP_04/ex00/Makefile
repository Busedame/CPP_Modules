CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OPTIONS = -c
SRC =	main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongCat.cpp \
		WrongAnimal.cpp
NAME = animalsounds
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32m🎉COMPILATION SUCCESS🥳\033[0m"
	@echo "\033[0;33mUsage: Usage: Run ./animalsounds.\033[0m"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) && echo "\033[0;31mRemoved object files 🗑️\033[0m"

fclean: clean
	@rm -f $(NAME) && echo "\033[0;31mRemoved executable 🗑️\033[0m"

re: fclean all

.PHONY: all clean fclean re