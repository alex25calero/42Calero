/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:52:03 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/10 11:52:59 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"

size_t	ft_strlcat (char *dest, const char *src, size_t s)
{
	size_t	destlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	if (destlen >= s)
		return (s + srclen);
	while (src[i] && ((destlen + i + 1) < s))
	{
		dest[destlen + i] = src[i];
		i++;
	}
	if ((destlen + i) < s)
		dest[destlen + i] = '\0';
	return (destlen + srclen);
}
