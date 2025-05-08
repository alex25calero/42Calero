/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:10:16 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/08 13:27:24 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unsigned(unsigned int num);
int		ft_unsigned_len(unsigned int num);

int	ft_unsigned_len(unsigned int num)
{
	int	len;

	len = 1;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void	ft_put_unsigned(unsigned int num)
{
	if (num >= 10)
		ft_put_unsigned(num / 10);
	ft_print_char((num % 10) + '0');
}

int	ft_print_unsigned(unsigned int num)
{
	ft_put_unsigned(num);
	return (ft_unsigned_len(num));
}
