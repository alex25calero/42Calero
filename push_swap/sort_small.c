/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:31:28 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/28 13:55:37 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	ft_sa(a);
}

void	sort_three(t_stack **a)
{
	while (!is_sorted(*a))
	{
		if ((*a)->value > (*a)->next->value)
		{
			ft_sa(a);
		}
		else
			ft_rra(a);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	dir;

	dir = ft_get_dir(*a);
	while ((*a)->value != find_min(*a))
	{
		if (dir == 1)
			ft_ra(a);
		else
			ft_rra(a);
	}
	ft_pb(a, b);
	sort_three(a);
	ft_pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	dir;

	dir = ft_get_dir(*a);
	while ((*a)->value != find_min(*a))
	{
		if (dir == 1)
			ft_ra(a);
		else
			ft_rra(a);
	}
	ft_pb(a, b);
	sort_four(a, b);
	ft_pa(a, b);
}
