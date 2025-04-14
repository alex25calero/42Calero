/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:01:55 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/11 23:30:08 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	totlen;
	char	*res;

	i = 0;
	j = 0;
	totlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(totlen * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	const char *s1 = "hola";
	const char *s2 = "mundo";
	char *s3 = ft_strjoin(s1, s2);
	
	printf("%s" , s3);
	free(s3);
	return (0);
}
*/