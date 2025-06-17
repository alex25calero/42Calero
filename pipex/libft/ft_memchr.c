/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:31:38 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/10 15:28:53 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		sbyte;
	size_t				i;

	i = 0;
	ptr = (const unsigned char *)s;
	sbyte = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == sbyte)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main() {
    unsigned char datos[] = {10, 20, 30, 40, 50};

    unsigned char *encontrado = ft_memchr(datos, 30, 5);

    if (encontrado != NULL) {
        printf("Valor encontrado: %u\n", *encontrado);
        printf("Índice: %ld\n", encontrado - datos);
    } else {
        printf("Valor no encontrado.\n");
    }

    return 0;
}
*/