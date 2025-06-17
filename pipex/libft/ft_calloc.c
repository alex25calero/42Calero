/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:14:59 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/11 12:21:55 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmem, size_t s)
{
	void	*res;
	size_t	res2;

	res2 = (unsigned int)nmem * (unsigned int)s;
	res = malloc(nmem * s);
	if (!res)
		return (NULL);
	ft_bzero(res, res2);
	return (res);
}
