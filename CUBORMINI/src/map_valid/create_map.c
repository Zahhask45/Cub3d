/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:55:57 by brumarti          #+#    #+#             */
/*   Updated: 2023/09/22 17:32:20 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->n_lines)
	{
		j = 0;
		while (j < map->n_cols)
		{
			ft_putchar_fd(map->map[i][j], 0);
			j++;
		}
		ft_putchar_fd('\n', 0);
		i++;
	}
}

void	get_size(char *path_map, t_map *map)
{
	int		len;
	char	*line;
	int		fd;

	fd = open(path_map, O_RDONLY);
	len = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			map->n_lines = len - 6;
			return ;
		}
		if (line[0] != '\n')
		{
			map->n_cols = ft_strlen(line);
			if (line[map->n_cols - 1] == '\n')
				map->n_cols--;
			len++;
		}
		free(line);
	}
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
		ft_putstr_fd("Invalid file type.\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	free(temp);
	ft_putstr_fd("Valid file, creating map...\n", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}

void	write_map(char *path_map, t_map *map)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	map->map = ft_memalloc(sizeof(char *) * map->n_lines);
	fd = open(path_map, O_RDONLY);
	init_textures(map, fd);
	i = 0;
	while (1)
	{
		j = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
			continue ;
		map->map[i] = ft_strdup(line);
		while (line[j])
		{
			if (line[j] == 'N' || line[j] == 'S' || line[j] == 'W' || line[j] == 'E')
			{
				map->p_pos[0] = j;
				map->p_pos[1] = i;
				map->p_dir = line[j];
			}
			j++;
		}
		free(line);
		i++;
	}
	map->map[i] = NULL;
	close(fd);
}

void	create_map(char *path_map, t_map *map)
{
	map->n_cols = 0;
	map->n_lines = 0;
	if (valid_path(path_map) == EXIT_FAILURE)
		return ;
	get_size(path_map, map);
	write_map(path_map, map);
	printf("lines: %d; col: %d\np_x: %d; p_y: %d; p_dir: %c\n", map->n_lines, map->n_cols, map->p_pos[0], map->p_pos[1], map->p_dir);
	printf("Floor RGB: %d,%d,%d; Ceiling RGB: %d,%d,%d\n", map->f_rgb[0], map->f_rgb[1], map->f_rgb[2], map->c_rgb[0], map->c_rgb[1], map->c_rgb[2]);
	printf("N Texture: %s;\nS Texture: %s;\nW Texture: %s;\nE Texture: %s;\n", map->img[0].path, map->img[1].path, map->img[2].path, map->img[3].path);
	print_map(map);
}