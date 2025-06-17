/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:06:28 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/19 16:18:20 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int main (int argc, char **argv)
{
	int i;
	
	if (argc == 2)
	{
		i = 0;		
		i = ft_strlen(argv[1]);
		i--;
		while (i >= 0)
		{
			write (1, &argv[1][i], 1);
			i--;
		}
	}
	write (1, "\n", 1);
	return (0);
}