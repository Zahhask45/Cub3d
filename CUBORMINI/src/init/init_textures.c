/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:50:54 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/30 14:19:04 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_texture_img(t_map *map, t_img *image, char *path)
{
	init_clean_img(image);
	image->mlx_img = mlx_xpm_file_to_image(map->mlx, path, &map->texture.size,
			&map->texture.size);
	image->addr = (int *)mlx_get_data_addr(image->mlx_img,
			&image->bits_per_pixel, &image->line_length, &image->endian);
	return ;
}

static int	*xpm_to_img(t_map *map, char *path)
{
	t_img	temp;
	int		*buf;
	int		x;
	int		y;

	init_texture_img(map, &temp, path);
	buf = ft_memalloc(1 * (sizeof * buf
				* map->texture.size * map->texture.size));
	y = 0;
	while (y < map->texture.size)
	{
		x = 0;
		while (x < map->texture.size)
		{
			buf[y * map->texture.size + x]
				= temp.addr[y * map->texture.size + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(map->mlx, temp.mlx_img);
	return (buf);
}

void	start_text(t_map *map)
{
	map->text = ft_memalloc(5 * sizeof * map->text);
	map->text[NORTH] = xpm_to_img(map, map->img[NORTH].path);
	map->text[SOUTH] = xpm_to_img(map, map->img[SOUTH].path);
	map->text[WEST] = xpm_to_img(map, map->img[WEST].path);
	map->text[EAST] = xpm_to_img(map, map->img[EAST].path);
}
