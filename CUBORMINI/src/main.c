/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:24:06 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/09/22 15:38:58 by jodos-sa         ###   ########.fr       */
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
	while (i < 5)
	{
		map.img[i].mlx_img = NULL;
		map.img[i].path = NULL;
		i++;
	}
	map.minimap.mlx_img = NULL;

	if (argc != 2)
		return (EXIT_FAILURE);
	create_map(argv[1], &map);


	
	//map = ft_memalloc(sizeof(t_map *));
	make_windows(&map);
	return (0);
}
