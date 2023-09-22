/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:07:41 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/09/22 14:46:01 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	close_win(t_map *map)
{
	//mlx_destroy_image(map->mlx, map->mlx_win);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	exit(EXIT_SUCCESS);
}

void	ft_init_img(t_map *map)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		map->img[i].mlx_img = NULL;
		map->img[i].path = NULL;
		i++;
	}
	i = 0;
	/* while (1 < 4)
	{
		map->img[i].mlx_img = mlx_xpm_file_to_image(map->mlx, map->img[i].path,
				&map->img[i].width, &map->img[i].height);
		i++;
	} */
	map->img[4].mlx_img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	i = 4;
	while (i < 5)
	{
		map->img[i].addr = mlx_get_data_addr(map->img[i].mlx_img,
			&map->img[i].bits_per_pixel, &map->img[i].line_length, &map->img[i].endian);
		i++;
	}
	
}

int	create_trgb(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}

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
	return (0);
}

void	make_windows(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "BANANA");
	ft_init_img(map);
	mlx_loop_hook(map->mlx, &render, map);
	mlx_hook(map->mlx_win, 2, 1L << 0, keyhooks, map);
	mlx_hook(map->mlx_win, 17, 0, close_win, map);
	mlx_loop(map->mlx);
}