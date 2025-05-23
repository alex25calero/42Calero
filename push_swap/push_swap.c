/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:48:34 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/23 13:15:59 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_args(int argc, char **argv)
{
	char	**values;
	int		i;

	values = split_args(argc, argv);
	i = 0;
	while (values[i])
	{
		if (!is_int_atoi(values[i]))
		{
			free_split(values);
			return (write(1, "Error 1\n", 8), 0);
		}
		i++;
	}
	if (!check_duplicates(values))
	{
		free_split(values);
		return (write(1, "Error 2\n", 8), 0);
	}
	free_split(values);
	return (1);
}
