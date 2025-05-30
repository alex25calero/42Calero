/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:43:59 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/15 19:05:01 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen((char *)str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i--;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (0);
}
/*
#include <stdio.h>
int main() {
    const char *texto;
    char *resultado;

	texto = "hola mundo esto es una busqueda de un caracter ultima posicion";
	resultado = ft_strrchr(texto, 'a');
    if (resultado != NULL) {
        printf("Encontrado: '%c' pos: %ld\n", *resultado, resultado - texto);
    } else {
        printf("Carácter no encontrado.\n");
    }

    return (0);
}
*/