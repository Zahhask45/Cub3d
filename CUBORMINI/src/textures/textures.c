/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:10:35 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/11/08 14:11:34 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
		colour = map->text[texture->index][texture->size
			* texture->y + texture->x];
		if (texture->index == NORTH || texture->index == EAST)
			colour = (colour >> 1) & 8355711;
		if (colour > 0)
			map->text_pix[y][x] = colour;
		y++;
	}
}
