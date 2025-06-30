/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:28:16 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/30 14:22:16 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**duplicate_map(char **original, int height)
{
	char	**copy;
	int		i;

	copy = malloc((height + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy)
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	find_player_position(char **grid, int height, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static int	has_unreachable(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_playable(t_map *map)
{
	char	**copy;
	int		x;
	int		y;
	int		result;
	int		i;

	copy = duplicate_map(map->grid, map->height);
	if (!copy)
		return (0);
	find_player_position(copy, map->height, &x, &y);
	flood_fill(copy, x, y);
	result = !has_unreachable(copy, map->height);
	i = 0;
	while (i < map->height)
	{
		free(copy[i]);
		i++;
	}
	free(copy);
	return (result);
}
