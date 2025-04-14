/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:05:12 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/14 13:10:38 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_ilen(int n)
{
	size_t	ilen;

	ilen = 0;
	if (n <= 0)
		ilen = 1;
	while (n != 0)
	{
		n = n / 10;
		ilen++;
	}
	return (ilen);
}

char *ft_itoa(int n)
{
	char	*res;
	long	nb;
	size_t 	len;

	len = ft_ilen(n);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	nb = n;
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		res[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (res);	
}
/*
#include <stdio.h>

int main(void)
{
	char *res1 = ft_itoa(157);
	char *res2 = ft_itoa(-2147483648);
	char *res3 = ft_itoa(10);
	char *res4 = ft_itoa(2147483647);

	printf ("%s\n", res1);
	printf ("%s\n", res2);
	printf ("%s\n", res3);
	printf ("%s\n", res4);
}
*/