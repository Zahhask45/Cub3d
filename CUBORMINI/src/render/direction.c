/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:52:40 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/11/08 13:53:08 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	forward(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player.pos_x + map->player.dir_x * MOVESPEED;
	new_y = map->player.pos_y + map->player.dir_y * MOVESPEED;
	return (validate(map, new_x, new_y));
}

int	backwards(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player.pos_x - map->player.dir_x * MOVESPEED;
	new_y = map->player.pos_y - map->player.dir_y * MOVESPEED;
	return (validate(map, new_x, new_y));
}

int	left(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player.pos_x + map->player.dir_y * MOVESPEED;
	new_y = map->player.pos_y - map->player.dir_x * MOVESPEED;
	return (validate(map, new_x, new_y));
}

int	right(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player.pos_x - map->player.dir_y * MOVESPEED;
	new_y = map->player.pos_y + map->player.dir_x * MOVESPEED;
	return (validate(map, new_x, new_y));
}
