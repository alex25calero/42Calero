/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:00:02 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/08 16:34:11 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex(unsigned int num, int upper);
int		ft_hex_len(unsigned int num);

void	ft_put_hex(unsigned int num, int upper)
{
	char	*base;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (num >= 16)
		ft_put_hex(num / 16, upper);
	ft_print_char(base[num % 16]);
}

int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 1;
	while (num >= 16)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int	ft_print_hex(unsigned int num, int upper)
{
	ft_put_hex(num, upper);
	return (ft_hex_len(num));
}
