/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:56:43 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/11 10:52:35 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sch, size_t len)
{
	size_t			i;
	size_t			j;
	unsigned char	*aux;

	if (len == 0)
		return (NULL);
	if (!sch)
		return ((char *)str);
	aux = (unsigned char *)str;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == sch[j] && sch[j] && str[i + j] && (i + j) < len)
			j++;
		if (sch[j] == '\0')
			return (aux + i);
		i++;
	}
}
