/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:40:10 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/30 19:18:09 by alegarci         ###   ########.fr       */
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

static int	can_move(t_game *game, int new_x, int new_y, char *prev_tile)
{
	char	next_tile;

	if (new_x < 0 || new_y < 0 || new_x >= game->map.width
		|| new_y >= game->map.height)
		return (0);
	next_tile = game->map.grid[new_y][new_x];
	if (next_tile == '1')
		return (0);
	if (next_tile == 'C')
		game->collected++;
	if (game->on_exit == 1)
		*prev_tile = 'E';
	else
		*prev_tile = '0';
	if (next_tile == 'E')
	{
		if (game->collected == game->map.count_c)
		{
			game->s++;
			(ft_putnbr_fd(game->s, 1), ft_putstr_fd("\n¡WIN!\n", 1), exit(0));
		}
		return (game->on_exit = 1, 1);
	}
	game->on_exit = 0;
	return (1);
}

static void	update_position(t_game *game, int new_x, int new_y, char prev_tile)
{
	game->map.grid[game->player_y][game->player_x] = prev_tile;
	game->player_x = new_x;
	game->player_y = new_y;
	game->s++;
	ft_putnbr_fd(game->s, 1);
	ft_putstr_fd("\n", 1);
	render_map(game);
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	prev_tile;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (!can_move(game, new_x, new_y, &prev_tile))
		return ;
	update_position(game, new_x, new_y, prev_tile);
}

void	init_player(t_game *game)
{
	int	x;
	int	y;

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
	game->s = 0;
	game->collected = 0;
}
