/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:51:57 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/03 15:51:57 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	pipex(char **argv, char **envp);
void	create_pipe(int pipe_fd[2]);
void	free_split(char **arr, int i);
void	close_pipes(int pipe_fd[2]);
void	execute_child1(char *cmd, int infile_fd, int pipe_fd[2], char **envp);
void	execute_child2(char *cmd, int outfile_fd, int pipe_fd[2], char **envp);
int		open_infile(const char *file);
int		open_outfile(const char *file);
char	**ft_split_cmd(const char *s);
char	*find_full_path(const char *cmd, char **envp);
char	*ft_strjoin_3(const char *s1, const char *s2, const char *s3);
char	*try_paths(char **paths, const char *cmd);
char	*get_path_env(char **envp);

#endif