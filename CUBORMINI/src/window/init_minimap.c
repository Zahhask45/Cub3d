/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:29:15 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/18 16:52:47 by jodos-sa         ###   ########.fr       */
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
	int x;

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

char	*minimap_line(t_map *map, t_mini *minimap, int y)
{
	char	*line;
	int		x;

	line = ft_memalloc((minimap->size + 1) * sizeof *line);
	if (!line)
		return (NULL);
	x = 0;
	while (x < minimap->size && x < map->n_cols)
	{
		if (!valid_map_coord(y + minimap->off_y, map->n_lines)
			|| !valid_map_coord(x + minimap->off_x, map->n_cols))
			line[x] = '\0';
		else if ((int)map->player.pos_x == (x + minimap->off_x)
			&& (int)map->player.pos_y == (y + minimap->off_y))
			line[x] = 'P';
		else if (map->map[y + minimap->off_y][x + minimap->off_x] == '1')
			line[x] = '1';
		else if (map->map[y + minimap->off_y][x + minimap->off_x] == '0')
			line[x] = '0';
		else
			line[x] = '\0';
		x++;
	}
	//printf("WOW: %d\n", minimap->size);
	return (line);
}

char	**gen_minimap(t_map *map, t_mini *minimap)
{
	int		y;
	char	**mini;

	mini = ft_memalloc((minimap->size + 1) * sizeof * mini);
	y = 0;
	while (y < minimap->size && y < map->n_lines)
	{
		mini[y] = minimap_line(map, minimap, y);
		y++;
	}
	return (mini);
}

//! Put in another file, in the init file
void	init_img(t_map *map, t_img *image, int width, int height)
{
	init_clean_img(image);
	image->mlx_img = mlx_new_image(map->mlx, width, height);
	image->addr = (int *)mlx_get_data_addr(image->mlx_img,
			&image->bits_per_pixel, &image->line_length, &image->endian);
	return ;
}

void	render_minimap(t_map *map, t_mini *minimap)
{
	int	img_size;

	img_size = 180 + minimap->tile_size;
	init_img(map, &map->minimap, img_size, img_size);
	draw_minimap(minimap);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->minimap.mlx_img,
		minimap->tile_size, HEIGHT - (180 + (minimap->tile_size * 2)));
	mlx_destroy_image(map->mlx, map->minimap.mlx_img);
}

void	init_minimap(t_map *map)
{
	t_mini	minimap;

	minimap.map = NULL;
	minimap.img = &map->minimap;
	minimap.view_dis = 6;
	minimap.size = (2 * minimap.view_dis) + 1;
	minimap.tile_size = 180 / (2 * minimap.view_dis);
	minimap.off_x = get_mini_offset(&minimap, map->n_cols,
			(int)map->player.pos_x);
	minimap.off_y = get_mini_offset(&minimap, map->n_lines,
			(int)map->player.pos_y);
	if (minimap.off_y < 0)
		minimap.off_y = 0;
	minimap.map = gen_minimap(map, &minimap);
	render_minimap(map, &minimap);
}


