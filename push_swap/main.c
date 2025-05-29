/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:26:35 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/29 16:47:15 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		printf("Node[%d]: %d\n", i, stack->value);
		// printf("index[%d]: %d\n", i, stack->index);
		stack = stack->next;
		i++;
	}
}

static void	ft_sort(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_list_size(*a);
	if (is_sorted(*a) == 1)
		return ;
	else if (len == 1)
		return ;
	else if (len == 2)
		sort_two(a);
	else if (len == 3)
		sort_three(a);
	else if (len == 4)
		sort_four(a, b);
	else if (len == 5)
		sort_five(a, b);
	else if (len > 5)
		ft_sort_big_list(a, b, len);
	else
		return ;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = create_stack(argc, argv);
	if (!a)
		return (1);
	assign_indices(a);
	ft_sort(&a, &b);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
