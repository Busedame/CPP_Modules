CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OPTIONS = -c
SRC = Megaphone.cpp
NAME = megaphone
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) $(OPTIONS) $< -o $@

$(NAME): $(OBJ)
	@echo "\033[0;36m  __  __  ____  ___    __    ____  _   _  ____  _  _  ____\033[0m"
	@echo "\033[0;36m (  \/  )( ___)/ __)  /__\  (  _ \( )_( )(  _  )( \( )( ___)\033[0m"
	@echo "\033[0;34m )    (  )__)( (_-. /(__)\  )___/ ) _ (  )(_)(  )  (  )__)\033[0m"
	@echo "\033[0;34m (_/\/\_)(____)\___/(__)(__)(__)  (_) (_)(_____)(_)\_)(____)\033[0m"
	@echo "\033[0;32m\nUsage: ./megaphone <x_amount_of_arguments>\033[0m"
	@echo "\033[0;32mThe program will convert all letters to uppercase.\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@if [ -n "$(OBJ)" ]; then \
		if [ -e $(OBJ) ]; then \
			rm -f $(OBJ) && echo "\033[0;31mRemoved object file 🗑️\033[0m"; \
		else \
			echo "\033[0;33mNo object files to remove 🤔\033[0m"; \
		fi; \
	fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME) && echo "\033[0;31mRemoved executable 🗑️\033[0m"; \
	else \
		echo "\033[0;33mNo executable to remove 🤔\033[0m"; \
	fi

re: fclean all

.PHONY: all clean fclean re