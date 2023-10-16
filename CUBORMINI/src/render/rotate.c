/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:58:43 by brumarti          #+#    #+#             */
/*   Updated: 2023/10/16 15:51:28 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	rotation(t_map *map, double rotspeed)
{
	double	temp_x;

	temp_x = map->player.dir_x;
	map->player.dir_x = map->player.dir_x * cos(rotspeed)
		- map->player.dir_y * sin(rotspeed);
	map->player.dir_y = temp_x * sin(rotspeed)
		+ map->player.dir_y * cos(rotspeed);
	temp_x = map->player.plane_x;
	map->player.plane_x = map->player.plane_x * cos(rotspeed)
		- map->player.plane_y * sin(rotspeed);
	map->player.plane_y = temp_x * sin(rotspeed)
		+ map->player.plane_y * cos(rotspeed);
	return (1);
}

int	rotate_player(t_map *map)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = ROTATION_SPEED * map->player.rotate;
	moved += rotation(map, rotspeed);
	return (moved);
}