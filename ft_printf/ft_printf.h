/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:29:40 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/08 16:06:19 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(char const *format, ...);
int	ft_print_str(char *str);
int	ft_print_nbr(int n);
int	ft_print_pt(void *ptr);
int	ft_print_unsigned(unsigned int num);
int	ft_print_hex(unsigned int num, int upper);
int	ft_format(char control, va_list args);
int	ft_print_char(int c);

#endif