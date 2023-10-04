/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:24:06 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/02 17:16:56 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	int		i;

	i = 0;
	map.f_rgb[0] = -1;
	map.f_rgb[1] = -1;
	map.f_rgb[2] = -1;
	map.c_rgb[0] = -1;
	map.c_rgb[1] = -1;
	map.c_rgb[2] = -1;

	map.texture.pos = 0.0;
	map.texture.step = 0.0;
	map.texture.x = 0;
	map.texture.y = 0;
	map.texture.size = 32;


	map.mlx = NULL;
	map.mlx_win = NULL;
	map.text_pix = NULL;
	map.text = NULL;

	map.player.dir = '\0';
	map.player.pos_x = 0.0;
	map.player.pos_y = 0.0;
	map.player.dir_x = 0.0;
	map.player.dir_y = 0.0;
	map.player.plane_x = 0.0;
	map.player.plane_y = 0.0;
	map.player.moved = 0;
	map.player.move_x = 0;
	map.player.move_y = 0;
	map.player.rotate = 0;

	map.map = NULL;




	
	while (i < 5)
	{
		map.img[i].mlx_img = NULL;
		map.img[i].path = NULL;
		map.img[i].bits_per_pixel = 0;
		map.img[i].line_length = 0;
		map.img[i].endian = 0;
		i++;
	}
	map.minimap.mlx_img = NULL;

	if (argc != 2)
		return (EXIT_FAILURE);
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
