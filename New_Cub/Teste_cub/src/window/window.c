/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:07:41 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/11/08 14:31:48 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	calculate_line(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dis = (ray->sid_dis_x - ray->delta_dis_x);
	else
		ray->wall_dis = (ray->sid_dis_y - ray->delta_dis_y);
	ray->line_height = (int)(HEIGHT / ray->wall_dis);
	ray->draw_start = -(ray->line_height) / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dis * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dis * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

int	ray(t_player *player, t_map *map)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = map->ray;
	while (x < WIDTH)
	{
		init_ray_info(x, &ray, player);
		dda(&ray, player);
		do_dda(map, &ray);
		calculate_line(&ray, player);
		update_text(map, &ray, &map->texture, x);
		x++;
	}
	return (0);
}

void	raycast_render(t_map *map)
{
	textures_pixel(map);
	init_ray(&map->ray);
	ray(&map->player, map);
	frame(map);
}

void	render_images(t_map *map)
{
	raycast_render(map);
	init_minimap(map);
}

void	make_windows(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "BANANA");
	start_text(map);
	render_images(map);
	input(map);
	mlx_loop_hook(map->mlx, &render, map);
	mlx_loop(map->mlx);
}
