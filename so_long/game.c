/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:59:12 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/30 19:19:03 by alegarci         ###   ########.fr       */
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

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
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

int	close_game(void *param)
{
	t_game	*game;
	t_map	*map;

	game = (t_game *)param;
	map = &game->map;
	if (map && map->grid)
		free_map(map->grid);
	if (game)
	{
		if (game->img_collectible)
			mlx_destroy_image(game->mlx, game->img_collectible);
		if (game->img_exit)
			mlx_destroy_image(game->mlx, game->img_exit);
		if (game->img_floor)
			mlx_destroy_image(game->mlx, game->img_floor);
		if (game->img_player)
			mlx_destroy_image(game->mlx, game->img_player);
		if (game->img_wall)
			mlx_destroy_image(game->mlx, game->img_wall);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
			(mlx_destroy_display(game->mlx), free(game->mlx));
	}
	exit(0);
}
