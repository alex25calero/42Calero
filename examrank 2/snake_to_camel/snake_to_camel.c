/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 23:31:41 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/19 23:52:26 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] != '_')
			{	
				write (1, &argv[1][i], 1);
			}
			else if (argv[1][i] == '_')
			{
				i++;
				argv[1][i] = argv[1][i] - 32;
				write (1, (&argv[1][i]), 1);
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
