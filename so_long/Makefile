# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/28 16:16:51 by alegarci          #+#    #+#              #
#    Updated: 2025/06/28 16:16:51 by alegarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === NOMBRE DEL EJECUTABLE ===
NAME		= so_long

# === DIRECTORIOS ===
INCLUDE_DIR	= include
MLX_DIR		= minilibx-linux
LIBFT_DIR	= libft
GNL_DIR		= gnl

# === LIBRERÍAS ===
LIBFT		= $(LIBFT_DIR)/libft.a
GNL		= $(GNL_DIR)/get_next_line.a
MLX		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# === ARCHIVOS FUENTE ===
SRCS		= main.c \
			  parse_map.c \
			  render.c \
			  controls.c \
			  game.c \
			  read_map.c \
			  validate_map.c \
			  map.c

OBJS		= $(SRCS:.c=.o)

# === COMPILADOR Y FLAGS ===
CC			= cc
CFLAGS		= -Wall -Wextra -Werror \
			  -I$(INCLUDE_DIR) \
			  -I$(LIBFT_DIR) \
			  -I$(GNL_DIR) \
			  -I$(MLX_DIR)

# === REGLAS ===
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	make -C $(LIBFT_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GNL):
	make -C $(GNL_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
