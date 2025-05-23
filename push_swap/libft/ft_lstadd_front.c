/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:14:34 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/15 18:11:43 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int main()
{
    t_list *head = NULL;

    t_list *n1 = ft_lstnew("Segundo");
    t_list *n2 = ft_lstnew("Primero");

    ft_lstadd_front(&head, n1);
    ft_lstadd_front(&head, n2);

    printf("Lista tras ft_lstadd_front:\n");
    print_list(head);

    return 0;
}
*/