/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:39:29 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/15 18:10:15 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h> 
int main(void)
{
    char str[10] = "Hello!";

    printf("Antes de ft_bzero: %s\n", str);

    // Llamamos a ft_bzero para poner a cero los primeros 5 bytes
    ft_bzero(str, 5);

    printf("Después de ft_bzero: %s\n", str);  // Debería mostrar un string vacío

    return 0;
}*/