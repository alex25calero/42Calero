/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:37:10 by alegarci          #+#    #+#             */
/*   Updated: 2025/04/08 17:57:26 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(char c)
{
	if (c >= 0 && c <= 126)
		return (1);
	else
		return (0);
}
