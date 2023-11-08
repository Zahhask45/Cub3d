/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:46:00 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/11/08 13:48:23 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_size2(char *line, int i, t_map *map)
{
	if (line[i] && (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E' || line[i] == 'F'
			|| line[i] == 'C' || line[i] == '\n'))
	{
		free(line);
		return (1);
	}
	if (line[i] == '1')
	{
		if (map->n_cols < last_char(line, '1'))
			map->n_cols = last_char(line, '1');
		return (2);
	}
	return (0);
}

void	get_size(char *path_map, t_map *map)
{
	int		len;
	int		i;
	char	*line;
	int		fd;

	fd = open(path_map, O_RDONLY);
	len = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i = 0;
		while (line[i] && ft_iswspace(line[i]))
			i++;
		if (get_size2(line, i, map) == 1)
			continue ;
		else if (get_size2(line, i, map) == 2)
			len++;
		free(line);
	}
	map->n_lines = len;
}
