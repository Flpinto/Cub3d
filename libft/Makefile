# COMPILATION
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

# DIRECTORIES
OBJ_DIR = obj/
SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c, obj/%.o, $(SRC))
INC = inc

# FILES
NAME    = libft.a

$(NAME): $(OBJ)
	@ar -rcs $@ $^
obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -I $(INC) -o $@ -c $<

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re