/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:24:23 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/27 16:31:39 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


static void	wrap(t_map *map, int x, int y)
{
	if (x > WIDTH - 20) //* 20 is the edge distance
	{
		x = 20;
		mlx_mouse_move(map->mlx, map->mlx_win, x, y);
	}
	if (x < 20) //* 20 is the edge distance
	{
		x = WIDTH - 20;
		mlx_mouse_move(map->mlx, map->mlx_win, x, y);
	}
}

static int	mouse_handler(int x, int y, t_map *map)
{
	static int	old_x = WIDTH / 2;

	wrap(map, x, y);
	if (x == old_x)
		return (0);
	else if (x < old_x)
	{
		map->player.rotate = -1;
		map->player.moved += rotate_player(map, 1);
	}
	else if (x > old_x)
	{
		map->player.rotate = 1;
		map->player.moved += rotate_player(map, 1);
	}
	map->player.rotate = 0;
	old_x = x;
	return (0);
}

void	input(t_map *map)
{
	mlx_hook(map->mlx_win, 17, 0, close_win, map);
	mlx_hook(map->mlx_win, 2, 1L << 0, keyhooks_press, map);
	mlx_hook(map->mlx_win, 3, 1L << 1, keyhooks_release, map);
	mlx_hook(map->mlx_win, 6, 1L << 6, mouse_handler, map);
	//mlx_mouse_hide(map->mlx, map->mlx_win);
}
