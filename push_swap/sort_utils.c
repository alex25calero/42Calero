/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:26:48 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/28 00:43:13 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	if (!a || !a->next)
		return (1);
	while (a->next != NULL && a->value < a->next->value)
		a = a->next;
	if (a->next == NULL)
		return (1);
	return (0);
}

int	ft_list_size(t_stack *begin_list)
{
	int	i;

	i = 1;
	while (begin_list->next)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

int	find_min(t_stack *a)
{
	int	min;

	min = INT_MAX;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

int	ft_get_dir(t_stack *a)
{
	int	smallest;
	int	index;
	int	smallest_index;
	int	half;

	index = 0;
	smallest_index = 0;
	smallest = INT_MAX;
	half = ft_list_size(a) / 2;
	while (a)
	{
		if (a->value < smallest)
		{
			smallest = a->value;
			smallest_index = index;
		}
		a = a->next;
		index++;
	}
	if (smallest_index < half)
		return (1);
	else
		return (-1);
}
