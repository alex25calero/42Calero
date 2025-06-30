/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:59:12 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/30 14:11:10 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_game *game)
{
	int	width;
	int	height;

	width = game->map.width * TILE_SIZE;
	height = game->map.height * TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error: mlx_init() falló\n", 2);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
	{
		ft_putstr_fd("Error: mlx_new_window() falló\n", 2);
		exit(1);
	}
}

static void	load_image(t_game *game, void **img, char *path)
{
	int	w;
	int	h;

	w = TILE_SIZE;
	h = TILE_SIZE;
	*img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!*img)
	{
		ft_putstr_fd("Error: no se pudo cargar ", 2);
		ft_putstr_fd(path, 2);
		ft_putchar_fd('\n', 2);
	}
}

void	load_images(t_game *game)
{
	load_image(game, (void **)&game->img_wall, "assets/wall.xpm");
	load_image(game, (void **)&game->img_floor, "assets/floor.xpm");
	load_image(game, (void **)&game->img_player, "assets/player.xpm");
	load_image(game, (void **)&game->img_exit, "assets/exit.xpm");
	load_image(game, (void **)&game->img_collectible, "assets/collect.xpm");
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_exit || !game->img_collectible)
	{
		ft_putstr_fd("Error: Fallo al cargar una o más imágenes\n", 2);
		exit(1);
	}
}
