/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:11:29 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/28 16:45:03 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define BUFFER_SIZE 1024

char	*read_file(const char *path)
{
	int		fd;
	char	*buf;
	char	*content;
	ssize_t	bytes;
	char	tmp[1025];

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening the file");
		return (NULL);
	}
	content = ft_strdup("");
	bytes = read(fd, tmp, 1024);
	while (bytes > 0)
	{
		tmp[bytes] = '\0';
		buf = content;
		content = ft_strjoin(buf, tmp);
		free(buf);
		bytes = read(fd, tmp, 1024);
	}
	close(fd);
	return (content);
}

char	**parse_map(const char *path)
{
	char *base;
	char **map;

	base = read_file(path);
	if (!base)
		return (NULL);
	map = ft_split(base, '\n');
	free(base);
	if (is_invalid(map))
	{
		free(map);
		return (NULL);
	}
	return (map);
}
