/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:48:34 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/28 13:54:43 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	create_stack(char **values, t_stack *a)
{
	int i = 0;
	while (values[i])
	{
		a->value = ft_atoi_safe(values[i]);
		a = a->next;
		i++;
	}
} */

/* void manage_error(t_stack *a, t_stack *b)
{
	ft_putstr_fd("Error:\n", 2);
	free(a);
	free(b);
	exit(1);
} */

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
