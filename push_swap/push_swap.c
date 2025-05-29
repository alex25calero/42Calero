/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:48:34 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/29 16:34:06 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**validate_args(int argc, char **argv)
{
	char	**values;
	int		i;

	values = split_args(argc - 1, argv + 1);
	i = 0;
	if (!values)
		return (write(1, "Error\n", 6), NULL);
	i = 0;
	while (values[i])
	{
		if (!is_int_atoi(values[i]))
			return (free_split(values), write(2, "Error\n", 6), NULL);
		i++;
	}
	if (!check_duplicates(values))
		return (free_split(values), write(2, "Error\n", 6), NULL);
	return (values);
}
