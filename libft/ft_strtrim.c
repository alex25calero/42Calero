/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:50:17 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/14 11:55:01 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}
/*
#include <stdio.h>

int	main(void)
{
	char *str1 = "hello world";
	char *set1 = "ehdl";
	char *res1 = ft_strtrim(str1, set1);
	char *str2 = "hola mundo";
	char *set2 = "ohdl";
	char *res2 = ft_strtrim(str2, set2);

	printf("%s\n", res1);
	printf("%s\n", res2);
}
*/