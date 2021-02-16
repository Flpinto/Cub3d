OS := $(shell uname)

NAME = Cub3D

LIBFT = ./libft/libft.a
LIBFT_SRC := $(wildcard libft/*.c)
LIBFT_OBJ := $(patsubst libft/%.c, libft/%.o, $(LIBFT_SRC))

CC = @gcc  -Wall -Wextra -Werror

#INCLUDES = -Iincludes -I/usr/local/include/ -Llibft -lft -lm -L/usr/local/lib/ -framework OpenGL -framework AppKit

INCLUDES = -Iincludes -I/usr/local/include/ -Llibft -lft -lm -L/usr/local/lib/ -L lmlx -lXext -lX11


SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c, obj/%.o, $(SRC))

MLX = ./mlx/libmlx.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@echo -e "Compiling Cub3D"
	@$(CC) $(OBJ) $(MLX) $(LIBFT) -o $(NAME) $(INCLUDES)

$(LIBFT): $(LIBFT_OBJ)
	@echo "----Compiling LIBFT----"
	@ar rcs $(LIBFT) $(LIBFT_OBJ)

libft/%.o: libft/%.c
	@$(CC) -Iincludes -c $< -o $@

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) -Iincludes -c $< -o $@

$(MLX):
	@echo "----Compiling MLX----"
	@make -C ./mlx

clean:
	@echo "----Clean obj----"
	@rm -rf libft/*.o obj/* mlx/*.o
	@rm -rf screenshot.bmp

fclean: clean
	@echo "----Clean libs and Cub3D----"
	@rm -rf $(NAME) *.dSYM $(LIBFT)
	@make -C ./mlx clean

re: fclean all

rerun: re run