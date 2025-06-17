/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:27:23 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/14 10:46:41 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checker(char c, char *str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (c == str[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	if (argc == 3)
	{
		while(argv[1][i] != '\0')
			i++;
		while (argv[2][j] != '\0')
		{
			argv[1][i] = argv[2][j];
			i++;
			j++;
		}
		i--;
		while (k <= i)
		{
			if (checker(argv[1][k], argv[1], k) == 1)
				write (1, &argv[1][k], 1);
			k++;
		}
	}
	write (1, "\n", 1);
}