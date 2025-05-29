/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:54:05 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/29 16:39:22 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_safe(char *str)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	sign = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + (str[i++] - '0');
	}
	return ((int)(n * sign));
}

t_stack	*lst_new(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	lst_addback(t_stack **lst, t_stack *new_node)
{
	t_stack	*temp;

	if (!lst || !new_node)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

void	clear_stack(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*new_node;
	int		i;
	int		num;
	char	**v;

	a = NULL;
	i = 0;
	v = validate_args(argc, argv);
	if (!v)
		return (NULL);
	while (v[i])
	{
		num = ft_atoi_safe(v[i]);
		new_node = lst_new(num);
		if (!new_node)
			return (free_split(v), clear_stack(&a), NULL);
		lst_addback(&a, new_node);
		i++;
	}
	free_split(v);
	return (a);
}
