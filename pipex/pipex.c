/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:51:55 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/03 15:51:55 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char **argv, char **envp)
{
	int	infile_fd;
	int	outfile_fd;
	int	pipe_fd[2];

	infile_fd = open_infile(argv[1]);
	outfile_fd = open_outfile(argv[4]);
	create_pipe(pipe_fd);
	execute_child1(argv[2], infile_fd, pipe_fd, envp);
	execute_child2(argv[3], outfile_fd, pipe_fd, envp);
	close_pipes(pipe_fd);
	close(infile_fd);
	close(outfile_fd);
	wait(NULL);
	wait(NULL);
}
