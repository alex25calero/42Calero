/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:01:48 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/13 12:59:50 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	int		temp;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	write (1, "sa\n", 3);
}

void	ft_sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;
	int		temp;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	write (1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*second;
	int		temp;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	temp = first->value;
	first->value = second->value;
	second->value = temp;
	write (1, "ss\n", 3);
}
