/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:00:42 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/27 13:12:31 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	int number;

	if (argc == 2)
	{
		i = 1;
		number = atoi(argv[1]);
		while (number >= i++)
		{
			if (number % i == 0)
			{
				printf("%d", i);
				if (number == i)
					break;
				printf("*");
				number /= i;
				i = 1;
			}	
		}
	}
	printf("\n");
	return (0);
}