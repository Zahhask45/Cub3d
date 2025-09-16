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

int	get_size2(char *line, int i, t_map *map, int *len)
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
		(*len)++;
	}
	return (0);
}

int	check_next(char *line, int fd, int len, int *flag)
{
	int	i;

	i = 0;
	while (line[i] && ft_iswspace(line[i]))
		i++;
	if (len > 1 && (!line[i] || line[i] == '\n'))
		*flag = 1;
	if (*flag && line[i] && !ft_iswspace(line[i]) && line[i] != '\n')
	{
		finish_gnl(line, fd);
		error_msg("Content after map.");
	}
	return (i);
}

void	get_size(char *path_map, t_map *map)
{
	int		len;
	int		flag;
	int		i;
	char	*line;
	int		fd;

	fd = open(path_map, O_RDONLY);
	len = 0;
	flag = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i = check_next(line, fd, len, &flag);
		if (get_size2(line, i, map, &len) == 1)
			continue ;
		free(line);
	}
	map->n_lines = len;
}

void	fill_spaces(t_map *map)
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
			if (c == ' ' && ((i > 0 && i < map->n_lines - 1)
					&& (j > 0 && j < (int)ft_strlen(map->map[i]) - 1)))
				map->map[i][j] = '0';
			else if (c == ' ' && ((i == 0 || i == map->n_lines - 1)
					|| (j == 0 || j == (int)ft_strlen(map->map[i]) - 1)))
				map->map[i][j] = '1';
			j++;
		}
		i++;
	}
}
