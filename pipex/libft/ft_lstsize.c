/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:14:15 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/15 18:22:51 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
int main()
{
    t_list *n1 = ft_lstnew("Uno");
    t_list *n2 = ft_lstnew("Dos");
    t_list *n3 = ft_lstnew("Tres");

    n1->next = n2;
    n2->next = n3;

    printf("Tamaño de la lista: %d\n", ft_lstsize(n1));  // Debería imprimir 3

    return 0;
}
*/