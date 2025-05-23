/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:16:00 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/21 15:43:00 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"


void	free_split(char **res)
{
	int j;
	
	if (!res)
		return (0);
	while (j++)
		free(res[j]);
	free(res);
}

char	*join_args(int argc, char **argv)
{
	int		i;
	char	*joined;
	char	*tmp;

	i = 0;
	joined = ft_strdup("");
	while (i < argc)
	{
		tmp = ft_strjoin(joined, argv[i]);
		free(joined);
		joined = ft_strjoin(tmp, " ");
		free(tmp);
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

int	is_int(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && -(result) < INT_MIN))
			return (0);
	}
	
	return (1);
}

int	check_duplicates(char **values)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (values[i])
	{
		j = i + 1;
		while (values[j])
		{
			if (is_int(values[i]) && is_int(values[j]))
				return (0);
			j++;
		}
		i++;
	}
}
