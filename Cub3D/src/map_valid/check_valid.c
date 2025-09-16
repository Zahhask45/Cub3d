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

	i = -1;
	while (++i < 4)
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
		{
			free(temp);
			clean_msg(map, NULL, "Invalid file type.", 0);
		}
		free(temp);
	}
}

void	rgb_player(t_map *map)
{
	if (map->f_rgb[0] == -1 || map->c_rgb[0] == -1)
		clean_msg(map, NULL, "Missing RGB.", 0);
	if (!map->img[NORTH].path || !map->img[SOUTH].path
		|| !map->img[WEST].path || !map->img[EAST].path)
		clean_msg(map, NULL, "Missing texture value.", 0);
	valid_textures(map);
	if (map->player.dir == 'X')
		clean_msg(map, NULL, "Missing Player.", 0);
}

void	search_border(t_map *map, int index, int line)
{
	int		i;
	char	*temp1;
	char	*temp2;

	i = 0;
	temp1 = ft_strdup(map->map[line - 1]);
	while (temp1[i] && i < index)
		i++;
	if (!temp1[i] || (temp1[i] != '1' && temp1[i] != '0'))
	{
		free(temp1);
		clean_msg(map, NULL, "Invalid char.", 0);
	}
	free(temp1);
	temp2 = ft_strdup(map->map[line + 1]);
	i = 0;
	while (temp2[i] && i < index)
		i++;
	if (!temp2[i] || (temp2[i] != '1' && temp2[i] != '0'))
	{
		free(temp2);
		clean_msg(map, NULL, "Invalid char.", 0);
	}
	free(temp2);
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
			if ((i > 0 && i < map->n_lines - 1) && c == '0')
				search_border(map, j, i);
			if ((i == 0 || i == map->n_lines - 1 || j == 0
					|| j == (int)ft_strlen(map->map[i]) - 1) && valid_border(c))
				clean_msg(map, NULL, "Invalid char.", 0);
			else if (c != '1' && c != '0' && c != map->player.dir)
				clean_msg(map, NULL, "Invalid char.", 0);
			j++;
		}
		i++;
	}
	rgb_player(map);
}
