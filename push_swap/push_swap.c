/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:48:34 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/21 15:45:25 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	validate_args(int argc, char **argv)
{
	char	**values;
	int		i;

	values = split_args(argc, argv);
	i = 0;
	while (values[i])
	{
		if (!is_int(values[i]))
		{
			free_split(values);
			return (0);
		}
	}
	if (!check_duplicates(values))
	{
		free_split(values);
		return (0);
	}
	return (1);
}