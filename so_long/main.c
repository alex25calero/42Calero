/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:44:21 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/30 22:48:10 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	validate_map(t_map *map)
{
	if (!is_rectangular(map->grid, map->height))
		return (0);
	if (!is_valid_char(map))
		return (0);
	if (!is_valid_wall(map))
		return (0);
	if (!has_required_elements(map))
		return (0);
	if (!is_playable(map))
		return (0);
	return (1);
}

int	is_ber_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.map.grid = NULL;
	if (argc != 2 || !is_ber_file(argv[1]))
	{
		ft_putstr_fd("Error\nUso: ./so_long mapa.ber\n", 2);
		return (1);
	}
	if (!load_map(argv[1], &game.map) || !validate_map(&game.map))
	{
		if (game.map.grid)
			free_map(game.map.grid);
		ft_putstr_fd("Error\nMapa inválido\n", 2);
		return (1);
	}
	init_player(&game);
	init_window(&game);
	load_images(&game);
	render_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	close_game(&game);
	return (0);
}
