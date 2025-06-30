/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:47:06 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/30 17:07:18 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_element(char c, t_map *map)
{
	if (c == 'P')
		map->count_p++;
	else if (c == 'E')
		map->count_e++;
	else if (c == 'C')
		map->count_c++;
}

int	is_rectangular(char **grid, int height)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(grid[0]);
	while (i < height)
	{
		if ((int)ft_strlen(grid[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_char(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			c = map->grid[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P'
				&& c != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map ->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	has_required_elements(t_map *map)
{
	int		i;
	int		j;

	map->count_p = 0;
	map->count_c = 0;
	map->count_e = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			count_element(map->grid[i][j], map);
			j++;
		}
		i++;
	}
	if (map->count_p != 1 || map->count_e < 1 || map->count_c < 1)
		return (0);
	return (1);
}
