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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	pipex(char **argv, char **envp);
void	create_pipe(int pipe_fd[2]);
int		open_infile(const char *file);
int		open_outfile(const char *file);


#endif