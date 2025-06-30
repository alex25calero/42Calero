NAME = libgnl.a

SRC =	get_next_line.c get_next_line_utils.c

SRCOBJ = $(SRC:.c=.o)

COMPILER = cc

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCOBJ)
	ar rcs $(NAME) $(SRCOBJ)

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -f $(SRCOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
