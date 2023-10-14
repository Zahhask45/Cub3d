/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:53:44 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/11 17:31:12 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	is_valid(t_map *map, double x, double y)
{
	if (x < 0.75 || x >= map->n_cols - 1.75)
		return (false);
	if (y < 0.75 || y >= map->n_lines - 1.25)
		return (false);
	if (map->map[(int)y][(int)x] != '0' && map->map[(int)y][(int)x] != map->player.dir)
		return (false);
	return (true);
}

int validate(t_map *map, double new_x, double new_y)
{
	int moved;

	moved = 0;
	if (is_valid(map, new_x, map->player.pos_y))
	{
		map->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid(map, map->player.pos_x, new_y))
	{
		map->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}


int	forward(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player.pos_x + map->player.dir_x * 0.1; //* 0.1 MOVESPEED
	printf("NEW X VALUE: %f\n", new_x);
	printf("POS X VALUE: %f\n", map->player.pos_x);
	new_y = map->player.pos_y + map->player.dir_y * 0.1; //* 0.1 MOVESPEED
	printf("NEW Y VALUE: %f\n", new_y);
	printf("POS Y VALUE: %f\n", map->player.pos_y);
	return (validate(map, new_x, new_y));
}

int	move_player(t_map *map)
{
	int moved;

	moved = 0;
	if (map->player.move_y == 1)
		moved += forward(map);
/* 	if (map->player.move_y == -1)
	if (map->player.move_x == -1)
	if (map->player.move_x == 1)
	if (map->player.move_y != 0) */

	return (moved);
}

int	render(t_map *map)
{
	map->player.moved += move_player(map);
	render_images(map);
	return (0);
}

