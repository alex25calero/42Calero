NAME = push_swap

# Archivos fuente
SRC = main.c \
	  push_swap.c \
	  push_swap_utils.c \
	  parser.c \
	  sort_small.c \
	  sort_big.c \
	  sort_utils.c \
	  src/ft_push.c \
	  src/ft_reverse.c \
	  src/ft_rotate.c \
	  src/ft_swap.c \

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = ./push_swap.h

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./include -I$(LIBFT_DIR)

# Comando por defecto
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
