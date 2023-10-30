/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:21:52 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/30 14:40:19 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	rgb_text(t_map *map, char *line, int j)
{
	if (line[j] == 'C' || line[j] == 'F')
			init_rgb(line, map, j);
	else if (line[j] == 'N' || line[j] == 'S'
		|| line[j] == 'E' || line[j] == 'W')
		get_textures(line, map, line[j], j);
}

void	p_pos(t_map *map)
{
	if (map->player.dir == 'S')
	{
		map->player.dir_x = 0;
		map->player.dir_y = 1;
		map->player.plane_x = -0.66;
		map->player.plane_y = 0;
	}
	else if (map->player.dir == 'N')
	{
		map->player.dir_x = 0;
		map->player.dir_y = -1;
		map->player.plane_x = 0.66;
		map->player.plane_y = 0;
	}
	else if (map->player.dir == 'W')
	{
		map->player.dir_x = -1;
		map->player.dir_y = 0;
		map->player.plane_x = 0;
		map->player.plane_y = -0.66;
	}
	else if (map->player.dir == 'E')
	{
		map->player.dir_x = 1;
		map->player.dir_y = 0;
		map->player.plane_x = 0;
		map->player.plane_y = 0.66;
	}
}