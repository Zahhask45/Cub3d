/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:05:29 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/11/08 14:05:50 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_ray(t_ray *ray)
{
	ray->cam_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sid_dis_x = 0;
	ray->sid_dis_y = 0;
	ray->wall_x = 0;
	ray->wall_dis = 0;
	ray->delta_dis_x = 0;
	ray->delta_dis_y = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_end = 0;
	ray->draw_start = 0;
}

void	init_ray_info(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->cam_x = 2 * x / (double)WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->cam_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->cam_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->delta_dis_x = fabs(1 / ray->dir_x);
	ray->delta_dis_y = fabs(1 / ray->dir_y);
}
