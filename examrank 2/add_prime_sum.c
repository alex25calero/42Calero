/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:04:37 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/19 16:05:25 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_put_char(int c)
{
	write (1, &c, 1);
}

int is_prime(int num)
{
	int i;

	i = 2;
	if (num <= 1)
		return (0);
	if (num == 2)
		return (1);
	if (num == 3)
		return (1);
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void ft_put_number(int n)
{
	long num;

	num = n;
	if (num >= 10)
		ft_put_number(num / 10);
	ft_put_char((num % 10) + '0');
}
int ft_atoi(char *num)
{
	int i;
	int result;

	result = 0;
	i = 0;
	while (num[i] >= '0' && num[i] <= '9')
	{
		result = result * 10 + (num[i] - '0');
		i++;
	}
	return (result);
}

int main(int argc, char **argv)
{
	int res;
	int nb;

	nb = ft_atoi(argv[1]);
	res = 0;
	if (argc != 2 || nb < 0)
	{
		write (1, "0\n", 2);
		return (0);
	}
	while (nb > 0)
	{
		if (is_prime(nb))
			res += nb;
		nb--;
	}
	ft_put_number(res);
	return (0);
}
