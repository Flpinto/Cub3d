# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flpinto <flpinto@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/04 10:31:31 by flpinto           #+#    #+#              #
#    Updated: 2020/06/06 13:05:17 by flpinto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BINARY = Cub3D

LIBFT = ./libft/libft.a
LIBFT_SRC := $(wildcard libft/*.c)
LIBFT_OBJ := $(patsubst libft/%.c, libft/%.o, $(LIBFT_SRC))

COMP = gcc -Wall -Wextra -Werror
INCLUDES = -Iincludes -Llibft -Lmlx -Imlx

SRC := $(wildcard src/*.c)
OBJ := $(patsubst src/%.c, obj/%.o, $(SRC))

GREEN = \e[1m\e[32m
RESET = \e[0m


all: $(BINARY)

$(BINARY): $(LIBFT) $(OBJ)
	@echo -e "$(GREEN)==> Making Cub3D$(RESET)"
	$(COMP) $(INCLUDES) $(OBJ) $(LIBFT) -o $(BINARY)

$(LIBFT): $(LIBFT_OBJ)
	@echo -e "$(GREEN)==> Making LIBFT$(RESET)"
	ar rcs $(LIBFT) $(LIBFT_OBJ)


libft/%.o: libft/%.c
	$(COMP) -Iincludes -c $< -o $@

obj/%.o: src/%.c
	mkdir -p obj
	$(COMP) -Iincludes -c $< -o $@

clean:
	rm -rf libft/*.o obj/*

fclean: clean
	rm -rf $(BINARY) $(LIBFT)

re: fclean all
