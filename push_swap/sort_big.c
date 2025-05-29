/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:37:02 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/29 16:54:19 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ft_sort_big_list(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	j;
	int	num;
	int	max_bits;

	i = 0;
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = (*a)->index;
			if (((num >> i) & 1) == 0)
				ft_pb(a, b);
			else
				ft_ra(a);
			j++;
		}
		while (*b)
			ft_pa(a, b);
		i++;
	}
}

void	assign_indices(t_stack *a)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = a;
	while (current)
	{
		index = 0;
		compare = a;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

