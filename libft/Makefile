# COMPILATION
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

# DIRECTORIES
OBJ_DIR = obj
DIR     = $(OBJ_DIR)

# FILES
NAME    = libft.a
SRC     = ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_strncmp.c\
		ft_strlen.c ft_strchr.c ft_strrchr.c \
		ft_tolower.c ft_toupper.c ft_bzero.c  \
		ft_memset.c ft_bzero.c ft_memcmp.c \
		ft_memchr.c ft_memcpy.c ft_memmove.c \
		ft_memccpy.c ft_strlcpy.c ft_strlcat.c \
		ft_strdup.c ft_calloc.c ft_strnstr.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c 
		
OBJ     := $(SRC:%.c=$(OBJ_DIR)/%.o)

$(NAME): $(OBJ)
	ar -rcs $@ $^

all: $(NAME)

clean:
	rm -rf $(DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)/%.o: %.c | $(DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re