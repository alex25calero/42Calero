/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:25:40 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/24 17:52:19 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	if (ac == 5)
	{
		pipex(av, envp);
	}
	else
	{
		ft_printf("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n");
		return (1);
	}
	return (0);
}
