OS := $(shell uname)

NAME = cub3D

LIBFT = ./libft/libft.a
LIBFT_SRC := $(wildcard libft/*.c)
LIBFT_OBJ := $(patsubst libft/%.c, libft/%.o, $(LIBFT_SRC))


CC = gcc  -Wall -Wextra -Werror 
MAKEFLAGS	+= --no-print-director


INCLUDES = -Iincludes -I/usr/local/include/ -Llibft -lft -lm -L/usr/local/lib/ -L lmlx -lXext -lX11 -I libft/inc/


SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c, obj/%.o, $(SRC))

MLX = mlx/libmlx.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@$(CC) $(OBJ) $(MLX) $(LIBFT) -o $(NAME) $(INCLUDES)
	@echo "\033[0;32m----Cub3d compiled----\033[0;0m"

$(LIBFT): $(LIBFT_OBJ)
	@echo "\033[0;36m----Compiling Start----"
	@$(MAKE) -C ./libft

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) -Iincludes -c $< -o $@

$(MLX):
	@echo "----Compiling MLX----"
	@$(MAKE) -C ./mlx
	@echo "\033[0;32m----MLX compiled----"


clean:
	@rm -rf obj/
	@$(MAKE) -C ./libft clean
	@$(MAKE) -C ./mlx clean
	@rm -rf save.bmp
	@echo "\033[0;33m----Obj and screenshot deleted----"

fclean: clean
	
	@rm -rf $(NAME)
	@$(MAKE) -C ./libft fclean
	@echo "\033[0;33m----Cub3D deleted----"

re: fclean all

.PHONY : all re fclean clean