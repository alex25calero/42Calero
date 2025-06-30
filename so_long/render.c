/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:26:40 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/30 13:55:37 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tile(t_game *g, char tile, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, g->img_floor, x, y);
	if (tile == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img_wall, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img_collectible, x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img_exit, x, y);
	else if (tile == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img_player, x, y);
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
			draw_tile(game, game->map.grid[y][x],
				x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
} 
