/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:21:52 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/11/24 18:43:32 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	create_trgb(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

int	is_valid_char(char c, char *play)
{
	int	i;

	i = 0;
	while (play[i])
	{
		if (c == play[i])
			return (1);
		i++;
	}
	return (0);
}

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
		map->player.dir_y = 1;
		map->player.plane_x = -0.66;
	}
	else if (map->player.dir == 'N')
	{
		map->player.dir_y = -1;
		map->player.plane_x = 0.66;
	}
	else if (map->player.dir == 'W')
	{
		map->player.dir_x = -1;
		map->player.plane_y = -0.66;
	}
	else if (map->player.dir == 'E')
	{
		map->player.dir_x = 1;
		map->player.plane_y = 0.66;
	}
}
