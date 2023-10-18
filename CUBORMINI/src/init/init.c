/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:42:55 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/14 16:11:48 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_clean_img(t_img *img)
{
	img->mlx_img = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
}

void	init_textinfo(t_text *texture)
{
	texture->pos = 0.0;
	texture->step = 0.0;
	texture->x = 0;
	texture->y = 0;
	texture->size = 32;
}

void	init_colors(t_map *map)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		map->c_rgb[i] = -1;
		map->f_rgb[i] = -1;
	}
	map->c_hex = 0x0;
	map->f_hex = 0x0;
}

void	init_player(t_player *player)
{
	player->dir = '\0';
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->moved = 0;
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
}

void	init_all(t_map *map)
{
	int	i;

	i = -1;
	map->mlx = NULL;
	map->mlx_win = NULL;
	init_player(&map->player);
	init_textinfo(&map->texture);
	init_colors(map);
	map->map = NULL;
	map->n_cols = 0;
	map->n_lines = 0;
	init_clean_img(&map->minimap);
	map->text = NULL;
	map->text_pix = NULL;
	while (++i < 5)
		init_clean_img(&map->img[i]);
}
