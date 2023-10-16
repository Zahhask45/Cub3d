/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:24:06 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/16 15:54:22 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (EXIT_FAILURE);
	init_all(&map);
	create_map(argv[1], &map);

	printf("Player Dir: %c\n", map.player.dir);

	if (map.player.dir == 'S')
	{
		map.player.dir_x = 0;
		map.player.dir_y = 1;
		map.player.plane_x = -0.66;
		map.player.plane_y = 0;
	}
	else if (map.player.dir == 'N')
	{
		map.player.dir_x = 0;
		map.player.dir_y = -1;
		map.player.plane_x = 0.66;
		map.player.plane_y = 0;
	}
	else if (map.player.dir == 'W')
	{
		map.player.dir_x = -1;
		map.player.dir_y = 0;
		map.player.plane_x = 0;
		map.player.plane_y = -0.66;
	}
	else if (map.player.dir == 'E')
	{
		map.player.dir_x = 1;
		map.player.dir_y = 0;
		map.player.plane_x = 0;
		map.player.plane_y = 0.66;
	}

	printf("DIR_X: %f\n", map.player.dir_x);
	printf("DIR_Y: %f\n", map.player.dir_y);
	printf("PLANE_X: %f\n", map.player.plane_x);
	printf("PLANE_Y: %f\n", map.player.plane_y);

	//map = ft_memalloc(sizeof(t_map *));
	make_windows(&map);
	return (0);
}
