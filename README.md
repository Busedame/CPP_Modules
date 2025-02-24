# 🖥️✨ **An introduction to C++!**

## 🚀 **Project Overview**  
This repository contains all the C++ modules that I did at 42 Berlin. It is a complete beginner's introduction to C++. Each module contains a small set of exercises, and each module/exercise introduces new concepts. 

##

### CPP_00

- Creating a class.
- Printing to stdout and reading from stdin.
- Private vs public attributes.
- Trimming strings using `setw()`.

##

### CPP_01

- Memory allocation.
- Referencing.
- Pointers to members.
- Usage of switch.

##

### CPP_02

- Integer/float conversions.
- Fixed point values.
- Orthodox canonical form.
- Overloads.

##

### CPP_03

- Derived classes.
- Class inheritance.

---

## 🧰 **Included Files**  
- All the functions.
- A `Makefile`.
- A header file.
- A test.c file with implementations of simple tests for each function.

---

## 🧑‍💻 **Cloning the Repository**

To get started, first clone the repository.
This command will clone the repo, and move you to the right directory:
```bash
git clone https://github.com/busedame/libft/ libft && cd libft
```
---

## 🖥️ **How to Compile and Run**  

### 💻 **Linux**  
1. **Compile the library**:  
   Run the following command to compile the library:  
   ```bash
   make
2. **Compile and run test**:
   Run the tests using:  
   ```bash
   make test

### 🍏 **Mac**  
Ran into some issues trying to compile on MacOS, but this seems to work:

**Step 1**
- Remove `#include <bsd/string.h>` from the header file.  
- Remove the `-lbsd` flag from the `Makefile`.

**Step 2**
- **Compile the library or tests**  
   Run either of the following commands:  
   ```bash
   make
   make test

---

## 🔗**Including Libft in your project**

Ensure that you have both your main project and the `libft` library in the same directory or organized in separate directories. You will need the path to your `libft` directory to link it in the `Makefile`.

- **In the header file**: Include `libft.h`

- **In the Makefile**:

  1. **Path to the libft project**:
     ```makefile
     LIBFT_PATH = <path_to_libft_directory>
     ```

  2. **Link the libft.a library**:
     ```makefile
     LIBFT = $(LIBFT_PATH)/libft.a
     LIBS = -L$(LIBFT_PATH) -lft
     ```

  3. **Compile the project and link with libft**:
     ```makefile
     $(NAME): $(OBJ) $(LIBFT)
         $(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)
     ```

  4. **Ensure that libft is compiled during the build process**:
     ```makefile
     $(LIBFT):
         $(MAKE) -C $(LIBFT_PATH)
     ```

  5. **Clean up object files**:
     ```makefile
     clean:
         rm -f $(OBJ)
         $(MAKE) -C $(LIBFT_PATH) clean
     ```

  6. **Clean up everything (object files, executables, and libft.a)**:
     ```makefile
     fclean: clean
         rm -f $(NAME)
         $(MAKE) -C $(LIBFT_PATH) fclean
     ```

**Example of Makefile**:
```bash
CC = cc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -c

# Path to the libft project
LIBFT_PATH = ./libft

# Source files for your project
SRC = src/main.c

# Object files for your project
OBJ = $(SRC:.c=.o)

# Final executable name
NAME = my_project

# Link the libft.a library
LIBFT = $(LIBFT_PATH)/libft.a
LIBS = -L$(LIBFT_PATH) -lft

# All: Compile both libft and your project
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

# Compile .c files to .o object files
%.o: %.c
	$(CC) $(CFLAGS) $(OPTIONS) $< -o $@

# Ensure that libft is compiled during the build process
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Clean up object files
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_PATH) clean

# Clean up everything (object files, executables, and libft.a)
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

# Rebuild everything (clean and then compile both libft and your project)
re: fclean all

.PHONY: all clean fclean re
```
*This project was finished Nov 30th 2023.*
