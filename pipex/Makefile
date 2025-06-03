NAME = pipex

# Archivos fuente
SRC = main.c \
	  pipex.c \
	  pipex_process.c \
	  pipex_utils.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Librerías externas
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTFT_DIR = ./ft_print
PRINTFT = $(PRINTFT_DIR)/ft_print.a

INCLUDES = -I. -I$(LIBFT_DIR) -I$(PRINTFT_DIR)

# Comando por defecto
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTFT):
	make -C $(PRINTFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTFT_DIR) fclean

re: fclean all
