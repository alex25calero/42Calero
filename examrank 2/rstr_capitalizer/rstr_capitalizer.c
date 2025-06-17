/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 23:57:00 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/20 00:29:28 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	if (argc > 1)
	{
		while (i < argc)
		{
			while (argv[i][j])
			{
				if ((argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0')  && (argv[i][j] >= 'a' && argv[i][j] <= 'z'))
				{
					argv[i][j] = argv[i][j] - 32;
					write (1, &argv[i][j], 1);
				}
				else if ((argv[i][j] >= 'A' && argv[i][j] <= 'Z') && !(argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0') )
				{
					argv[i][j] = argv[i][j] + 32;
					write (1, &argv[i][j], 1);
				}
				else
					write (1, &argv[i][j], 1);
				j++;
			}
			j = 0;
			write (1, "\n", 1);
			i++;
		}
	}
	if (argc == 1)
		write (1, "\n", 1);
}