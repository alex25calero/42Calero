/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:20:03 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/15 16:08:57 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*link;

	link = (t_list*)malloc(sizeof(t_list));
	if(!link)
		return (NULL);
	link->content = (void*)content;
	link->next = NULL;
	return (link);
}
