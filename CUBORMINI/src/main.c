/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:24:06 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/25 15:14:32 by jodos-sa         ###   ########.fr       */
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
	make_windows(&map);
	return (0);
}
