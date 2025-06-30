/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:40:10 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/30 16:00:57 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 115)
		move_player(game, 0, 1);
	else if (keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 100)
		move_player(game, 1, 0);
	return (0);
}

static void	update_player_pos(t_game *game, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	old_x = game->player_x;
	old_y = game->player_y;
	game->map.grid[old_y][old_x] = '0';
	game->map.grid[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->steps++;
	ft_putnbr_fd(game->steps, 1);
	ft_putstr_fd("\n", 1);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_y < 0 || new_x >= game->map.width || new_y >= game->map.height)
		return ;
	if (game->map.grid[new_y][new_x] == '1')
		return ;
	if (game->map.grid[new_y][new_x] == 'C')
		game->collected++;
	if (game->map.grid[new_y][new_x] == 'E')
	{
		if (game->collected == game->map.count_c)
		{
			game->steps++;
			ft_putnbr_fd(game->steps, 1);
			ft_putstr_fd("\n¡Has ganado!\n", 1);
			exit(0);
		}
		return ;
	}
	update_player_pos(game, new_x, new_y);
	render_map(game);
}

void	init_player(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
	game->steps = 0;
	game->collected = 0;
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

