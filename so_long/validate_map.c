/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegarci <alegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:51:36 by alegarci          #+#    #+#             */
/*   Updated: 2025/06/30 14:07:55 by alegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* int	validate_map(t_map *map)
{
	if (!is_rectangular(map->grid, map->height))
		return (0);
	if (!is_valid_char(map))
		return (0);
	if (!is_valid_wall(map))
		return (0);
	if (!has_required_elements(map))
		return (0);
	if (!is_playable(map))
		return (0);
	return (1);
}
 */
int	validate_map(t_map *map)
{
	if (!is_rectangular(map->grid, map->height))
		return (0);
	if (!is_valid_char(map))
		return (0);
	if (!is_valid_wall(map))
		return (0);
	if (!has_required_elements(map))
		return (0);
	if (!is_playable(map))
		return (0);
	return (1);
}
