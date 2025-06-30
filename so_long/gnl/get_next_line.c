/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:17:35 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/30 13:15:41 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *backup)
{
	int		i;
	char	*line;

	i = 0;
	if (!backup || backup[0] == '\0')
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_backup(char *backup)
{
	size_t	i;
	size_t	j;
	char	*new_backup;

	if (!backup)
		return (free(backup), NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
		return (free(backup), NULL);
	i++;
	new_backup = malloc((ft_strlen_gnl(backup + i) + 1) * sizeof(char));
	if (!new_backup)
		return (free(backup), NULL);
	j = 0;
	while (backup[i])
		new_backup[j++] = backup[i++];
	new_backup[j] = '\0';
	free (backup);
	return (new_backup);
}

char	*read_to_backup(int fd, char *backup)
{
	char	*buff;
	char	*tmp;
	ssize_t	bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr_gnl(backup, '\n') && bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buff), free(backup), NULL);
		buff[bytes] = '\0';
		tmp = backup;
		backup = ft_strjoin_gnl(backup, buff);
		free(tmp);
	}
	free(buff);
	if (bytes == -1)
		return (free (backup), NULL);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_to_backup(fd, backup);
	if (!backup || backup[0] == '\0')
		return (free(backup), backup = NULL, NULL);
	line = extract_line(backup);
	backup = update_backup(backup);
	if (!line || line[0] == '\0')
		return (free (line), NULL);
	return (line);
}
/* int main()
{
	char *line;

	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	if (!line)
	{
		printf("Error reading line");
		printf("line is NULL from: %d\n", fd);
		close(fd);
		return (1);
	}
	else
	{
		printf("%s\n",line);
		free(line);
	}
	while ((line = get_next_line(fd)))
	{
		printf("%s\n",line);
		free(line);
	}
	close(fd);
}
 */