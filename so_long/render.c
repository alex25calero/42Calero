/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:26:40 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/30 19:11:50 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map.grid[y][x];
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
	if (game->player_x == x && game->player_y == y)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_player, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}
