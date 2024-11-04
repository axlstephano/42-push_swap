
# VARIABLES

NAME = push_swap
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

TESTS = $(wildcard tests/*.c) 

LIB_DIR = lib/lib42.a

CC = gcc
# CFLAGS = -Wall -Wextra -Werror

# RULES

all: $(NAME)

library:
	@make -s -C lib

$(NAME): $(OBJ) library
	$(CC) $(OBJ) $(TESTS) $(LIB_DIR) -o $@

clean:
	@rm -f $(OBJ) $(NAME)
	@make clean -s -C lib

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C lib

re: fclean all

.PHONY: all clean fclean re

