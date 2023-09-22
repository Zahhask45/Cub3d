/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:41:10 by brumarti          #+#    #+#             */
/*   Updated: 2023/09/22 17:28:18 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_rgb(char *line, t_map *map, int j)
{
	int		index;
	int		start;
	char	*temp;

	index = 0;
	while (line[j] && index < 3)
	{
		if (ft_isdigit(line[j]))
		{
			start = j;
			if (line[j - 1] == '-')
			{
				ft_putstr_fd("Error\nInvalid RGB\n", STDERR_FILENO);
				exit(1);
			}
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
	if (index == 2)
	{
		ft_putstr_fd("Error\nMissing RGB\n", STDERR_FILENO);
		exit(1);
	}
}

void	loop_textures(char *line, t_map *map, char c, int j)
{
	int	i;
	int	start;

	i = j + 2;
	while (line[i])
	{
		if (ft_isalpha(line[i]) || line[i] == '.' || line[i] == '/')
		{
			start = i;
			while (line[i] && !ft_iswspace(line[i]) && line[i] != '\n')
				i++;
			if (c == 'N')
				map->img[0].path = ft_substr(line, start, i - start);
			else if (c == 'S')
				map->img[1].path = ft_substr(line, start, i - start);
			else if (c == 'W')
				map->img[2].path = ft_substr(line, start, i - start);
			else
				map->img[3].path = ft_substr(line, start, i - start);
			break;
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
		{
			ft_putstr_fd("Error\nMap can't come first.\n", STDERR_FILENO);
			exit(1);
		}
		while (ft_iswspace(j))
			j++;
		if (line[j] != '\n')
			i++;
		else
			continue ;
		if (line[j] == 'C' || line[j] == 'F')
			init_rgb(line, map, j + 1);
		else if (line[j] == 'N' || line[j] == 'S'
			|| line[j] == 'E' || line[j] == 'W')
			get_textures(line, map, line[j], j);
		free(line);
	}
}