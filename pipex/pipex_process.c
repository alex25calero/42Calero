/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:51:39 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/03 15:51:39 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_child1(char *cmd, int infile_fd, int pipe_fd[2], char **envp)
{
	pid_t	pid;
	char	**args;
	char	*path;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (dup2(infile_fd, STDIN_FILENO) < 0
			|| dup2(pipe_fd[1], STDOUT_FILENO) < 0)
			exit(EXIT_FAILURE);
		close_pipes(pipe_fd);
		close(infile_fd);
		args = ft_split_cmd(cmd);
		path = find_full_path(args[0], envp);
		if (!path || execve(path, args, envp) == -1)
		{
			perror("execve");
			exit(127);
		}
	}
}

void	execute_child2(char *cmd, int outfile_fd, int pipe_fd[2], char **envp)
{
	pid_t	pid;
	char	*path;
	char	**args;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (dup2(pipe_fd[0], STDIN_FILENO) < 0
			|| dup2(outfile_fd, STDOUT_FILENO) < 0)
			exit(EXIT_FAILURE);
		close_pipes(pipe_fd);
		close(outfile_fd);
		args = ft_split_cmd(cmd);
		path = find_full_path(args[0], envp);
		if (!path || execve(path, args, envp) == -1)
		{
			perror("execve");
			exit(127);
		}
	}
}

void	close_pipes(int pipe_fd[2])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}
