/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:55:21 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/08 13:04:03 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ptr_len(unsigned long long ptr);
void	ft_put_ptr(unsigned long long ptr);

int	ft_print_pt(void *ptr)
{
	unsigned long long	dir;

	if (!ptr)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	dir = (unsigned long long)ptr;
	ft_print_str("0x");
	ft_put_ptr(dir);
	return (2 + ft_ptr_len(dir));
}

int	ft_ptr_len(unsigned long long ptr)
{
	int	len;

	len = 1;
	while (ptr >= 16)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

void	ft_put_ptr(unsigned long long ptr)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr >= 16)
		ft_put_ptr(ptr / 16);
	ft_print_char(base[ptr % 16]);
}
