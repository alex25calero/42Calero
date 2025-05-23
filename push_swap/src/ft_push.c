/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:02:46 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/13 13:18:22 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_pa(t_stack **a, t_stack **b)
{
		t_stack	*first;

		if (!b || !*b)
			return ;
		first = *b;
		*b = (*b)->next;
		first->next = *a;
		*a = first;
		write (1, "pa\n", 3);
}
void	ft_pb(t_stack **a, t_stack **b)
{
		t_stack	*first;

		if (!a || !*a)
			return ;
		first = *a;
		*a = (*a)->next;
		first->next = *b;
		*b = first;
		write (1, "pb\n", 3);
}