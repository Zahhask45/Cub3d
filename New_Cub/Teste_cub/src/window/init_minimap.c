/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:29:15 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/11/08 14:51:21 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*minimap_line(t_map *map, t_mini *minimap, int y)
{
	char	*line;
	int		x;

	line = ft_memalloc((minimap->size + 1) * sizeof * line);
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
	if (minimap.off_x < 0)
		minimap.off_x = 0;
	minimap.map = gen_minimap(map, &minimap);
	render_minimap(map, &minimap);
	free_tab((void **)minimap.map);
}
