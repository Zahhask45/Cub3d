/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:07:41 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/14 15:31:59 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/* void	ft_init_img(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		map->img[i].mlx_img = mlx_xpm_file_to_image(map->mlx, map->img[i].path,
				&map->img[i].width, &map->img[i].height);
		i++;
	}
	map->img[4].mlx_img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	i = 0;
	while (i < 5)
	{
		map->img[i].addr = mlx_get_data_addr(map->img[i].mlx_img,
			&map->img[i].bits_per_pixel, &map->img[i].line_length, &map->img[i].endian);
		i++;
	}
	
} */

int	create_trgb(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}
/* 
void	put_image(t_map *map, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > HEIGHT - 1 || x < 0
		|| x > WIDTH - 1)
		return ;
	pixel = (map->img[4].addr + (y * map->img[4].line_length
				+ x * (map->img[4].bits_per_pixel / 8)));
	*(int *)pixel = color;
}

int	render(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				put_image(map, x, y, create_trgb(0, map->c_rgb[0],
						map->c_rgb[1], map->c_rgb[2]));
			else
				put_image(map, x, y, create_trgb(0, map->f_rgb[0],
						map->f_rgb[1], map->f_rgb[2]));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img[4].mlx_img, 0, 0);
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->minimap.mlx_img, 10, 10);
	return (0);
} */

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	textures_pixel(t_map *map)
{
	int	i;

	if (map->text_pix)
		free_tab((void **)map->text_pix);
	map->text_pix = ft_memalloc((HEIGHT + 1) * (sizeof * map->text_pix));
	i = 0;
	while (i < HEIGHT)
	{
		map->text_pix[i] = ft_memalloc((WIDTH + 1) * (sizeof * map->text_pix));
		i++;
	}
}

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
		if (ray->map_y < 0.25 || ray->map_x < 0.25
			|| ray->map_y > map->n_lines - 0.25 || ray->map_x > map->n_cols - 1.25)
			break ;
		else if (map->map[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
}

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
		ray->wall_x = player->pos_y + ray->wall_dis *ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dis *ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	get_index(t_map *map, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			map->texture.index = WEST;
		else
			map->texture.index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			map->texture.index = SOUTH;
		else
			map->texture.index = NORTH;
	}
}

void	update_text(t_map *map, t_ray *ray, t_text *texture, int x)
{
	int	y;
	int	colour;

	get_index(map, ray);
	texture->x = (int)(ray->wall_x * texture->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		texture->x = texture->size - texture->x - 1;
	texture->step = 1.0 * texture->size / ray->line_height;
	texture->pos = (ray->draw_start - HEIGHT / 2
				+ ray->line_height / 2) * texture->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		texture->y = (int)texture->pos & (texture->size - 1);
		texture->pos += texture->step;
		colour = map->text[texture->index][texture->size * texture->y + texture->x];
		if (texture->index == NORTH || texture->index == EAST)
			colour = (colour >> 1) & 8355711;
		if (colour > 0)
			map->text_pix[y][x] = colour;
		y++;
	}
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

void	start_image(t_map *map, t_img *image)
{
	image->mlx_img = NULL;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_length = 0;
	image->endian = 0;

	
	image->mlx_img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	image->addr = (int *)mlx_get_data_addr(image->mlx_img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	return ;
}

void	set_image(t_img *image, int x, int y, int colour)
{
	int	pixel;

	pixel = y * (image->line_length / 4) + x;
	image->addr[pixel] = colour;
}

void	set_frame(t_map *map, t_img *image, int x, int y)
{
	if (map->text_pix[y][x] > 0)
		set_image(image, x, y, map->text_pix[y][x]);
	else if (y < HEIGHT / 2)
			set_image(image, x, y, map->c_hex);
	else if (y < HEIGHT - 1)
			set_image(image, x, y, map->f_hex);
}

void	frame(t_map *map)
{
	t_img	image;
	int		x;
	int		y;

	image.mlx_img = NULL;
	start_image(map, &image);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			set_frame(map, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(map->mlx, map->mlx_win, image.mlx_img, 0, 0);
	mlx_destroy_image(map->mlx, image.mlx_img);
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
	//ft_init_img(map);
	mlx_loop_hook(map->mlx, &render, map);
	mlx_loop(map->mlx);
}