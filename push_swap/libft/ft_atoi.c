/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:42:22 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/15 18:08:29 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	result;
	unsigned int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
#include <stdio.h>

int	main(void)
{
	char *ejemplo1 = "   1234";
	char *ejemplo2 = "   +-5678";
	char *ejemplo3 = "-42";
	char *ejemplo4 = "   \t\n  9000abc";
	char *ejemplo5 = "abc123";

	printf("Ejemplo 1: \"%s\" → %d\n", ejemplo1, ft_atoi(ejemplo1));
	printf("Ejemplo 2: \"%s\" → %d\n", ejemplo2, ft_atoi(ejemplo2));
	printf("Ejemplo 3: \"%s\" → %d\n", ejemplo3, ft_atoi(ejemplo3));
	printf("Ejemplo 4: \"%s\" → %d\n", ejemplo4, ft_atoi(ejemplo4));
	printf("Ejemplo 5: \"%s\" → %d\n", ejemplo5, ft_atoi(ejemplo5));

	return (0);
}
*/