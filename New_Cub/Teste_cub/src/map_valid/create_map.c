/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:55:57 by brumarti          #+#    #+#             */
/*   Updated: 2023/11/27 15:58:37 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	valid_map(char *path_map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(path_map, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			if (i == 0)
				return (0);
			break ;
		}
		if (line[0] != '\n' && !ft_isvalidc(line[0]))
		{
			finish_gnl(line, fd);
			return (0);
		}
		free(line);
		i++;
	}
	return (close(fd), 1);
}

int	valid_path(char *path_map)
{
	char	*temp;

	if (open(path_map, O_RDONLY) == -1)
	{
		ft_putstr_fd("File doesn't exist.\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	temp = ft_substr(path_map, ft_strlen(path_map) - 4, 4);
	if (ft_strncmp(temp, ".cub", 4) != EXIT_SUCCESS)
	{
		free(temp);
		ft_putstr_fd("Invalid file type.\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	free(temp);
	ft_putstr_fd("Valid file, creating map...\n", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}

int	write_map2(t_map *map, char *line, int j, int i)
{
	char	*line2;

	if (line[0] == '\n')
	{
		free(line);
		return (1);
	}
	line2 = ft_strdup(line);
	map->map[i] = ft_strtrim(line2, "\n");
	free(line2);
	while (line[j])
	{
		if (line[j] == 'N' || line[j] == 'S'
			|| line[j] == 'W' || line[j] == 'E')
		{
			map->player.pos_x = j + 0.5;
			map->player.pos_y = i + 0.5;
			if (map->player.dir != 'X')
				clean_msg(map, line, "Multiple players!", 1);
			map->player.dir = line[j];
			map->map[i][j] = '0';
		}
		j++;
	}
	return (0);
}

void	write_map(char *path_map, t_map *map)
{
	int		i;
	int		j;
	char	*line;

	map->map = ft_memalloc(sizeof(char *) * (map->n_lines + 1));
	map->fd = open(path_map, O_RDONLY);
	init_textures(map, map->fd);
	i = 0;
	while (1)
	{
		j = 0;
		line = get_next_line(map->fd);
		if (!line)
			break ;
		if (write_map2(map, line, j, i) == 1)
			continue ;
		free(line);
		i++;
	}
	map->map[map->n_lines] = NULL;
	close(map->fd);
}

void	create_map(char *path_map, t_map *map)
{
	map->n_cols = 0;
	map->n_lines = 0;
	map->f_rgb[0] = -1;
	map->c_rgb[0] = -1;
	map->player.dir = 'X';
	if (valid_path(path_map) == EXIT_FAILURE)
		exit(1);
	if (!valid_map(path_map))
		error_msg("Invalid char !");
	get_size(path_map, map);
	write_map(path_map, map);
	validate_map(map);
}
