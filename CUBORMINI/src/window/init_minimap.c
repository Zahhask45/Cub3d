/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:29:15 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/09/22 17:36:00 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	minimap_pix(t_map *map, int x, int y, int colour)
{
	char	*pix;

	if (y < 0 || y > HEIGHT - 1 || x < 0
		|| x > WIDTH - 1)
		return ;
	pix = (map->minimap.addr + (y * map->minimap.line_length
				+ x * (map->minimap.bits_per_pixel / 8)));
	*(int *)pix = colour;
}

void	draw_minimap(t_map *map, int x, int y, int colour)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 7)
		{
			minimap_pix(map, x + j, y + i, colour);
			j++;
		}
		i++;
	}
}

void	make_minimap(t_map *map)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				draw_minimap(map, j * 7, i * 7, 0x000000);
			else if (map->map[i][j] == '0')
				draw_minimap(map, j * 7, i * 7, create_trgb(0, map->c_rgb[0],
						map->c_rgb[1], map->c_rgb[2]));
			else if (is_valid_char(map->map[i][j], "NSEW"))
				draw_minimap(map, j * 7, i * 7, 0xEEEE20);
			else
				draw_minimap(map, j * 7, i * 7, 0x050505);
			j++;
		}
		i++;
	}
}

void	init_minimap(t_map *map)
{
	map->minimap.mlx_img = mlx_new_image(map->mlx, map->n_cols * 7, map->n_lines * 7);
	map->minimap.addr = mlx_get_data_addr(map->minimap.mlx_img, 
				&map->minimap.bits_per_pixel, &map->minimap.line_length, &map->minimap.endian);
	make_minimap(map);
}

