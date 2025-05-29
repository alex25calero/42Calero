/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:16:00 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/28 13:49:11 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **res)
{
	int	j;

	j = 0;
	if (!res)
		return ;
	while (res[j])
	{
		free(res[j]);
		j++;
	}
	free(res);
}

char	*join_args(int argc, char **argv)
{
	int		i;
	char	*joined;
	char	*tmp;

	i = 0;
	joined = ft_strdup("");
	if (!joined)
		return (NULL);
	while (i < argc)
	{
		tmp = ft_strjoin(joined, argv[i]);
		free(joined);
		joined = tmp;
		if (i < argc - 1)
		{
			tmp = ft_strjoin(joined, " ");
			free(joined);
			joined = tmp;
		}
		i++;
	}
	return (joined);
}

char	**split_args(int argc, char **argv)
{
	char	*joined;
	char	**values;

	joined = join_args(argc, argv);
	if (!joined)
		return (NULL);
	values = ft_split(joined, ' ');
	free(joined);
	return (values);
}

int	is_int_atoi(char *str)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	sign = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + (str[i++] - '0');
		if ((sign == 1 && n > INT_MAX) || (sign == -1 && -(n) < INT_MIN))
			return (0);
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	check_duplicates(char **values)
{
	int	i;
	int	n1;
	int	j;
	int	n2;

	i = 0;
	while (values[i])
	{
		n1 = ft_atoi_safe(values[i]);
		j = i + 1;
		while (values[j])
		{
			n2 = ft_atoi_safe(values[j]);
			if (n1 == n2)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
