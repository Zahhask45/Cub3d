/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:41:10 by brumarti          #+#    #+#             */
/*   Updated: 2023/09/28 15:05:05 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_rgb(char *line, t_map *map)
{
	int		index;
	int		j;
	int		start;
	char	*temp;

	index = 0;
	j = 1;
	while (line[j])
	{
		if (ft_isdigit(line[j]))
		{
			start = j;
			while (ft_isdigit(line[j]))
				j++;
			temp = ft_substr(line, start, j - start);
			if (line[0] == 'C')
				map->c_rgb[index] = ft_atoi(temp);
			else
				map->f_rgb[index] = ft_atoi(temp);
			index++;
			free(temp);
		}
		j++;
	}
	
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

void	loop_textures(char *line, t_map *map, char c)
{
	int	i;
	int	start;

	i = 2;
	while (line[i])
	{
		if (ft_isalpha(line[i]) || line[i] == '.' || line[i] == '/')
		{
			start = i;
			while (line[i] && !ft_iswspace(line[i]))
				i++;
			if (c == 'N')
				map->img[NORTH].path = ft_substr(line, start, i - start);
			else if (c == 'S')
				map->img[SOUTH].path = ft_substr(line, start, i - start);
			else if (c == 'W')
				map->img[WEST].path = ft_substr(line, start, i - start);
			else
				map->img[EAST].path = ft_substr(line, start, i - start);
		}
		i++;
	}
}

void	get_textures(char *line, t_map *map, char c)
{
	if (c == 'N' || c == 'S')
	{
		if (line[1] == 'O')
			loop_textures(line, map, c);
	}
	else if (c == 'W' && line[1] == 'E')
		loop_textures(line, map, c);
	else if (c == 'E' && line[1] == 'A')
		loop_textures(line, map, c);
}

void	init_textures(t_map *map, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd);
		if (line[0] != '\n')
			i++;
		else
			continue ;
		if (line[0] == 'C' || line[0] == 'F')
			init_rgb(line, map);
		else if (line[0] == 'N' || line[0] == 'S'
			|| line[0] == 'E' || line[0] == 'W')
			get_textures(line, map, line[0]);
		free(line);
	}
}