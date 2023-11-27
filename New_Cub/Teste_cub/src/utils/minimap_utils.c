/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:40:56 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/11/08 14:50:28 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_minimap_pix(t_mini *minimap, int x, int y, int colour)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->size)
	{
		j = 0;
		while (j < minimap->size)
		{
			set_image(minimap->img, x + j, y + i, colour);
			j++;
		}
		i++;
	}
}

void	put_tile(t_mini *minimap, int x, int y)
{
	if (minimap->map[y][x] == '1')
		set_minimap_pix(minimap, x * minimap->tile_size,
			y * minimap->tile_size, 0x000000);
	else if (minimap->map[y][x] == '0')
		set_minimap_pix(minimap, x * minimap->tile_size,
			y * minimap->tile_size, 0xE6E6E6);
	else if (minimap->map[y][x] == 'P')
		set_minimap_pix(minimap, x * minimap->tile_size,
			y * minimap->tile_size, 0xEEEE20);
	else if (minimap->map[y][x] == ' ')
		set_minimap_pix(minimap, x * minimap->tile_size,
			y * minimap->tile_size, 0x050505);
}

void	draw_minimap(t_mini *minimap)
{
	int	y;
	int	x;

	y = 0;
	while (y < minimap->size)
	{
		x = 0;
		while (x < minimap->size)
		{
			if (!minimap->map[y] || !minimap->map[y][x]
				|| minimap->map[y][x] == '\0')
				break ;
			put_tile(minimap, x, y);
			x++;
		}
		y++;
	}
}

int	get_mini_offset(t_mini *minimap, int map_size, int pos)
{
	if (pos > minimap->view_dis && map_size - pos > minimap->view_dis + 1)
		return (pos - minimap->view_dis);
	if (pos > minimap->view_dis && map_size - pos <= minimap->view_dis + 1)
		return (map_size - minimap->size);
	return (0);
}

bool	valid_map_coord(int coord, int size)
{
	if (coord < size)
		return (true);
	return (false);
}
