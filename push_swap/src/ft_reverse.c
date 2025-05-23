/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:02:44 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/23 13:32:01 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_stack **a)
{
	t_stack	*prev;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = *a;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *a;
	*a = last;
	write (1, "rra\n", 3);
}

void	ft_rrb(t_stack **b)
{
	t_stack	*prev;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	prev = *b;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *b;
	*b = last;
	write (1, "rrb\n", 3);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	t_stack	*prev;
	t_stack	*last;

	if (a && *a && (*a)->next)
	{
		prev = *a;
		while (prev->next->next)
			prev = prev->next;
		last = prev->next;
		prev->next = NULL;
		last->next = *a;
		*a = last;
	}
	if (b && *b && (*b)->next)
	{
		prev = *b;
		while (prev->next->next)
			prev = prev->next;
		last = prev->next;
		prev->next = NULL;
		last->next = *b;
		*b = last;
	}
	write (1, "rrr\n", 3);
}
