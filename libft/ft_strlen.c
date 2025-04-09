/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:10:16 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/09 15:42:43 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(const char *str)
{
	unsigned int	i;

	while (str[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>
void	main(void)
{
	int	i;

	i = ft_strlen("hola mundo");
	printf ("%d", i);
}
*/
