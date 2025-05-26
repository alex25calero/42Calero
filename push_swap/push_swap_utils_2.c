/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:54:05 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/25 18:34:03 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi_safe(char *str)
{
	int		i = 0;
	int		sign = 1;
	long	n = 0;

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

t_stack create_list(char **values)
{
    t_stack list;
    t_stack new_node;
    int i;
    int num;

	i = 0;
    while (values[i])
    {
        num = ft_atoi_safe(values[i]);
        new_node = lst_new(num);
        if (!&new_node)
        {
            lst_clear(&list);  // libera la lista ya creada
            return (NULL);
        }
        lst_addback(&list, new_node);
        i++;
    }
    return (list);
}
