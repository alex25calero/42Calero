/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:26:35 by alegarci          #+#    #+#             */
/*   Updated: 2025/05/23 13:33:36 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(2, "No args provided\n", 17);
		return (1);
	}
	if (!validate_args(argc, argv))
		return (1);
	write(1, "Arguments OK\n", 13);
	return (0);
}
