/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:29:42 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/08 16:44:24 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char control, va_list args)
{
	if (control == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (control == 'p')
		return (ft_print_pt(va_arg(args, char *)));
	else if (control == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (control == 'i' || control == 'd')
		return (ft_print_nbr(va_arg(args, int)));
	else if (control == 'u')
		return (ft_print_unsigned(va_arg(args, int)));
	else if (control == 'X')
		return (ft_print_hex(va_arg(args, int), 1));
	else if (control == 'x')
		return (ft_print_hex(va_arg(args, int), 0));
	else if (control == '%')
	{
		write (1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		counter;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	counter = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			counter += ft_format(format[i + 1], args);
			i++;
		}
		else
		{
			ft_print_char(format[i]);
			counter++;
		}
		i++;
	}
	va_end(args);
	return (counter);
}

//int	main(void)
//{
//	int		ret1, ret2;
//	void	*ptr = (void *)0x12345678;
//
//	printf("----- %%x / %%X -----\n");
//	ret1 = printf("ORIGINAL : %x | %x | %x\n", 42, -1, -42);
//	ret2 = ft_printf("FT_PRINTF: %x | %x | %x\n", 42, -1, -42);
//	printf("Return ORIGINAL : %d\n", ret1);
//	printf("Return FT_PRINTF: %d\n\n", ret2);
//
//	ret1 = printf("ORIGINAL : %X | %X | %X\n", 42, -1, -42);
//	ret2 = ft_printf("FT_PRINTF: %X | %X | %X\n", 42, -1, -42);
//	printf("Return ORIGINAL : %d\n", ret1);
//	printf("Return FT_PRINTF: %d\n\n", ret2);
//
//	printf("----- %%d -----\n");
//	ret1 = printf("ORIGINAL : %d | %d\n", 123, -456);
//	ret2 = ft_printf("FT_PRINTF: %d | %d\n", 123, -456);
//	printf("Return ORIGINAL : %d\n", ret1);
//	printf("Return FT_PRINTF: %d\n\n", ret2);
//
//	printf("----- %%s -----\n");
//	ret1 = printf("ORIGINAL : %s\n", "Hello, world!");
//	ret2 = ft_printf("FT_PRINTF: %s\n", "Hello, world!");
//	printf("Return ORIGINAL : %d\n", ret1);
//	printf("Return FT_PRINTF: %d\n\n", ret2);
//
//	printf("----- %%c -----\n");
//	ret1 = printf("ORIGINAL : %c %c %c\n", 'A', 'B', 'C');
//	ret2 = ft_printf("FT_PRINTF: %c %c %c\n", 'A', 'B', 'C');
//	printf("Return ORIGINAL : %d\n", ret1);
//	printf("Return FT_PRINTF: %d\n\n", ret2);
//
//	printf("----- %%p -----\n");
//	ret1 = printf("ORIGINAL : %p\n", ptr);
//	ret2 = ft_printf("FT_PRINTF: %p\n", ptr);
//	printf("Return ORIGINAL : %d\n", ret1);
//	printf("Return FT_PRINTF: %d\n\n", ret2);
//
//	printf("----- %%u -----\n");
//	ret1 = printf("ORIGINAL : %u | %u\n", 123, -1);
//	ret2 = ft_printf("FT_PRINTF: %u | %u\n", 123, -1);
//	printf("Return ORIGINAL : %d\n", ret1);
//	printf("Return FT_PRINTF: %d\n\n", ret2);
//
//	ft_printf("%%-------------%%");
//
//	return (0);
//}
