/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:29:58 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/08 17:52:35 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	buffer1[20];
	char	buffer2[20];
	int		i;

		for (i = 0; i < 20; i++)
	{
		buffer1[i] = 'X';
		buffer2[i] = 'X';
	}

	ft_memset(buffer1, 'A', 10);

	memset(buffer2, 'A', 10);

	printf("ft_memset : ");
	for (i = 0; i < 20; i++)
		printf("%c", buffer1[i]);
	printf("\n");

	printf("memset    : ");
	for (i = 0; i < 20; i++)
		printf("%c", buffer2[i]);
	printf("\n");

	return (0);
}
*/