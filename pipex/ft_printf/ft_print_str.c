/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:47:43 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/07 18:28:28 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		count += 6;
		return (count);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		count++;
		i++;
	}
	return (count);
}

//int main(void)
//{
//	char *st = NULL;
//	printf("%s\n", st);
//	return (0);
//	int i = 0;
//	int res = ft_print_str("text\n", i);
//	int res2 = printf("text\n");
//	printf ("%d\n", res);
//	printf ("%d\n", res2);
//	res = ft_print_str("", i);
//	res2 = printf(NULL);
//	printf ("%d\n", res);
//	printf ("%d\n", res2);
//    char *str = NULL;
//
//    if (str != NULL) {
//        printf("El string es: %s\n", str);
//    } else {
//        printf("El string es: (null)\n");
//    }
//
//    return 0;
//}