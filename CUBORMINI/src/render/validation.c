/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:50:55 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/11/08 13:51:24 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	is_valid(t_map *map, double x, double y)
{
	int		inty;
	int		intx;
	bool	valid;

	valid = false;
	intx = floor(x);
	inty = floor(y);
	if (map->player.pos_y < y)
		inty = floor(y + 0.25);
	else if (map->player.pos_y > y)
		inty = floor(y - 0.25);
	if (map->player.pos_x < x)
		intx = floor(x + 0.25);
	else if (map->player.pos_x > x)
		intx = floor(x - 0.25);
	if (intx <= 0 || inty <= 0)
		valid = false;
	if (map->map[inty][intx] == '0')
		valid = true;
	else
		valid = false;
	return (valid);
}

int	validate(t_map *map, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid(map, new_x, map->player.pos_y))
	{
		map->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid(map, map->player.pos_x, new_y))
	{
		map->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}
