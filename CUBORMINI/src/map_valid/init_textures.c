/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:41:10 by brumarti          #+#    #+#             */
/*   Updated: 2023/10/30 14:40:25 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	to_hex(t_map *map)
{
	int				r;
	int				g;
	int				b;

	r = map->c_rgb[0];
	g = map->c_rgb[1];
	b = map->c_rgb[2];
	map->c_hex = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	r = map->f_rgb[0];
	g = map->f_rgb[1];
	b = map->f_rgb[2];
	map->f_hex = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void	init_rgb(char *line, t_map *map, int j)
{
	int		index;
	int		start;
	char	*temp;

	index = 0;
	while (line[++j] && index < 3)
	{
		if (ft_isdigit(line[j]))
		{
			start = j;
			if (line[j - 1] == '-')
				error_msg("Invalid RGB.");
			while (ft_isdigit(line[++j]))
				;
			temp = ft_substr(line, start, j - start);
			if (line[0] == 'C')
				map->c_rgb[index++] = ft_atoi(temp);
			else
				map->f_rgb[index++] = ft_atoi(temp);
			free(temp);
		}
	}
	if (index == 2)
		error_msg("Missing RGB.");
	to_hex(map);
}

void	loop_textures(char *line, t_map *map, char c, int j)
{
	int	i;
	int	start;

	i = j + 2;
	while (line[i])
	{
		if (ft_isalpha(line[i]) || line[i] == '.'
			|| line[i] == '/' || line[i] == '.' || line[i] == '/')
		{
			start = i;
			while (line[i] && !ft_iswspace(line[i]) && line[i] != '\n')
				i++;
			if (c == 'N')
				map->img[NORTH].path = ft_substr(line, start, i - start);
			else if (c == 'S')
				map->img[SOUTH].path = ft_substr(line, start, i - start);
			else if (c == 'W')
				map->img[WEST].path = ft_substr(line, start, i - start);
			else
				map->img[EAST].path = ft_substr(line, start, i - start);
			break ;
		}
		i++;
	}
}

void	get_textures(char *line, t_map *map, char c, int j)
{
	if (c == 'N' || c == 'S')
	{
		if (line[j + 1] == 'O')
			loop_textures(line, map, c, j);
	}
	else if (c == 'W' && line[j + 1] == 'E')
		loop_textures(line, map, c, j);
	else if (c == 'E' && line[j + 1] == 'A')
		loop_textures(line, map, c, j);
}

void	init_textures(t_map *map, int fd)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < 6)
	{
		j = 0;
		line = get_next_line(fd);
		if (line[0] == '1' || line[0] == '0')
			error_msg("Map can't come first.");
		while (ft_iswspace(line[j]))
			j++;
		if (line[j] != '\n')
			i++;
		else
		{
			free(line);
			continue ;
		}
		rgb_text(map, line, j);
		free(line);
	}
}
