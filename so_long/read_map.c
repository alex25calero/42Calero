/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:02:24 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/30 13:31:07 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(const char *filename)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	load_map(const char *filename, t_map *map)
{
	int		fd;
	int		i;
	char	*line;
	int		len;

	i = 0;
	map->height = count_lines(filename);
	if (map->height <= 0)
		return (0);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(map->grid), 0);
	line = get_next_line(fd);
	while (line && i < map->height)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		map->grid[i++] = line;
		line = get_next_line(fd);
	}
	map->grid[i] = NULL;
	map->width = ft_strlen(map->grid[0]);
	close(fd);
	return (1);
}
