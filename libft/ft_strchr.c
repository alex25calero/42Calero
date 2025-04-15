/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:36:59 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/15 19:08:59 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return ('\0');
}
/*
#include <stdio.h>
int main() {
    const char *texto;
    char *resultado;

	texto = "hola mundo";
	resultado = ft_strchr(texto, 'a');
    if (resultado != NULL) {
        printf("Encontrado: '%c' pos: %ld\n", *resultado, resultado - texto);
    } else {
        printf("Carácter no encontrado.\n");
    }

    return (0);
}
*/