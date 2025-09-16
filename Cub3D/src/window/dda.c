/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:01:49 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/11/08 14:03:11 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	dda(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sid_dis_x = (player->pos_x - ray->map_x) * ray->delta_dis_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sid_dis_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_dis_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sid_dis_y = (player->pos_y - ray->map_y) * ray->delta_dis_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sid_dis_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_dis_y;
	}
}

void	do_dda(t_map *map, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sid_dis_x < ray->sid_dis_y)
		{
			ray->sid_dis_x += ray->delta_dis_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sid_dis_y += ray->delta_dis_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25 || ray->map_x < 0.25 || ray->map_y > map->n_lines
			- 0.25 || ray->map_x > map->n_cols - 1.25)
			break ;
		else if (map->map[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
}
