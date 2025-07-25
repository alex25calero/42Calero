/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:51:47 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/03 15:51:47 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	open_outfile(const char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	create_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

char	*ft_strjoin_3(const char *s1, const char *s2, const char *s3)
{
	char	*tmp;
	char	*joined;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
		return (NULL);
	joined = ft_strjoin(tmp, s3);
	free(tmp);
	return (joined);
}


void	command_permission_denied(const char *cmd)
{
	write(2, "pipex:", 6);
	if (cmd && *cmd)
		write(2, cmd, ft_strlen(cmd));
	write(2, " Permission denied\n", 20);
	exit(126);
}