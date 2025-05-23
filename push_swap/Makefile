NAME = pushswap
SRC =	push_swap.c \
		src/ft_push.c \
		src/ft_reverse.c \
		src/ft_rotate.c \
		src/ft_swap \

SRCOBJ = $(SRC:.c=.o)
LIB_DIR = libft
LIBFT = $(LIB_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT)(OBJS)
	cp $(LIBFT), 
	mv libft.a $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(SRCOBJ)
	$(NAME) $(SRCOBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(LIB_DIR) -c $< -o $@

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -f $(SRCOBJ)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re