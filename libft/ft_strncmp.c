/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:52:09 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/09 13:29:05 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int	i;

	i = 0;
	while (i < n && (str1[i] || str2[i]))
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
    // Casos de prueba simples
    printf("Test 1: %d\n", ft_strncmp("hola", "hola", 4));  // Debe devolver 0
    printf("Test 2: %d\n", ft_strncmp("hola", "holA", 4));  // Debe devolver > 0
    printf("Test 3: %d\n", ft_strncmp("abc", "abcd", 4));   // Debe devolver < 0
    printf("Test 4: %d\n", ft_strncmp("abc", "abc", 4));    // Debe devolver 0
    printf("Test 5: %d\n", ft_strncmp("abc", "", 1));       // Debe devolver > 0
    printf("Test 6: %d\n", ft_strncmp("", "abc", 1));       // Debe devolver < 0
    printf("Test 7: %d\n", ft_strncmp("", "", 1));          // Debe devolver 0
    printf("Test 8: %d\n", ft_strncmp("abc", "abcd", 0));   // Debe devolver 0
    printf("Test 9: %d\n", ft_strncmp("abcd", "abc", 3));   // Debe devolver 0
    printf("Test 10: %d\n", ft_strncmp("abc", "abc", 3));   // Debe devolver 0

    return 0;
}
*/