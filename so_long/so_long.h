/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:51:57 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/03 15:51:57 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# define TILE_SIZE 50

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		count_p;
	int		count_e;
	int		count_c;
}	t_map;

typedef struct s_game
{
	
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	int		player_x;
	int		player_y;
	int		s;
	int		collected;
	int 	on_exit;
	t_map	map;
}	t_game;

int		is_rectangular(char **grid, int height);
int		is_valid_char(t_map *map);
int		load_map(const char *filename, t_map *map);
int		has_required_elements(t_map *map);
int 	is_valid_wall(t_map *map);
int		validate_map(t_map *map);
int		is_playable(t_map *map);
int		handle_key(int keycode, t_game *game);
int		close_window(t_game *game);
int		close_game(void *param);
void	init_player(t_game *game);
void	free_map(char **map);
void	render_map(t_game *game);
void	init_window(t_game *game);
void	load_images(t_game *game);
void	move_player(t_game *game, int dx, int dy);

#endif