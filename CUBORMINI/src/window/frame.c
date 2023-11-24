/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:25:52 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/11/08 14:26:17 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	start_image(t_map *map, t_img *image)
{
	image->mlx_img = NULL;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_length = 0;
	image->endian = 0;
	image->mlx_img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	image->addr = (int *)mlx_get_data_addr(image->mlx_img,
			&image->bits_per_pixel, &image->line_length, &image->endian);
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
