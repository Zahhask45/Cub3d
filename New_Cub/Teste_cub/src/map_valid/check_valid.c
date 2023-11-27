/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:53:32 by brumarti          #+#    #+#             */
/*   Updated: 2023/11/27 15:51:55 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	valid_border(char c)
{
	if (c != ' ' && c != '1' && c != '\t')
		return (1);
	return (0);
}

void	valid_textures(t_map *map)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (ft_strncmp(map->img[i].path, map->img[j].path,
					ft_strlen(map->img[i].path)) == 0)
				clean_msg(map, NULL, "Textures can't be the same.", 0);
			j++;
		}
		if (open(map->img[i].path, O_RDONLY) == -1)
			clean_msg(map, NULL, "Invalid Dir.", 0);
		temp = ft_substr(map->img[i].path, ft_strlen(map->img[i].path) - 4, 4);
		if (ft_strncmp(temp, ".xpm", 4) != 0)
			error_msg("Invalid file type.");
		free(temp);
		i++;
	}
}

void	rgb_player(t_map *map)
{
	if (map->f_rgb[0] == -1 || map->c_rgb[0] == -1)
		error_msg("Missing RGB");
	valid_textures(map);
	if (map->player.dir == 'X')
		clean_msg(map, NULL, "Missing Player.", 0);
}

void	validate_map(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < map->n_lines)
	{
		j = 0;
		while (j < (int)ft_strlen(map->map[i]))
		{
			c = map->map[i][j];
			if (i == 0 || i == map->n_lines - 1 || j == 0
				|| j == (int)ft_strlen(map->map[i]) - 1)
			{
				if (valid_border(c))
					clean_msg(map, NULL, "Invalid char.", 0);
			}
			else if (c != '1' && c != '0' && c != ' ' && c != map->player.dir)
				error_msg("Invalid char!");
			j++;
		}
		i++;
	}
	rgb_player(map);
}
