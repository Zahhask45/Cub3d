/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:08:12 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/11/27 15:59:12 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	clean_map(t_map *map)
{
	free_tab((void **)map->map);
	if (map->img[NORTH].path)
		free(map->img[NORTH].path);
	if (map->img[SOUTH].path)
		free(map->img[SOUTH].path);
	if (map->img[WEST].path)
		free(map->img[WEST].path);
	if (map->img[EAST].path)
		free(map->img[EAST].path);
}

void	finish_gnl(char *line, int fd)
{
	free (line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
	close(fd);
}

void	clean_msg(t_map *map, char *line, char *msg, int gnl)
{
	if (gnl)
		finish_gnl(line, map->fd);
	clean_map(map);
	error_msg(msg);
}

void	error_dup(t_map *map, char *line)
{
	finish_gnl(line, map->fd);
	if (map->img[NORTH].path)
		free(map->img[NORTH].path);
	if (map->img[SOUTH].path)
		free(map->img[SOUTH].path);
	if (map->img[WEST].path)
		free(map->img[WEST].path);
	if (map->img[EAST].path)
		free(map->img[EAST].path);
	free_tab((void **)map->map);
	error_msg("Duplicate Texture !");
}
