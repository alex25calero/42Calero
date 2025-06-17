NAME = libftprintf.a
SRC =	ft_printf.c \
			ft_print_char.c \
			ft_print_nbr.c \
			ft_print_str.c \
			ft_print_pt.c \
			ft_print_unsigned.c \
			ft_print_hex.c

SRCOBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCOBJ)
	ar rcs $(NAME) $(SRCOBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRCOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re