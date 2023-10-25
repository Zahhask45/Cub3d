/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:53:44 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/25 14:29:02 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	is_valid(t_map *map, double x, double y)
{
	int inty;
	int	intx;
	bool valid;

	valid = false;
	intx = floor(x);
	inty = floor(y);

	if (map->player.pos_y < y)
		inty = floor(y + 0.25);
	else if (map->player.pos_y > y)
		inty = floor(y - 0.25);
	if (map->player.pos_x < x)
		intx = floor(x + 0.25);
	else if (map->player.pos_x > x)
		intx = floor(x - 0.25);
	//! Questionable condition 
	if (intx <= 0 || inty <= 0)
			valid = false;
	if (map->map[inty][intx] == '0')
		valid = true;
	else
		valid = false;
	printf("=========================\n");
	printf("POS Y: %f\n", y);
	printf("POS X: %f\n", x);
	printf("POS INT Y: %d\n", inty);
	printf("POS INT X: %d\n", intx);
	printf("MAP POSITION %c\n", map->map[inty][intx]);
	printf("=========================\n");
	return (valid);
}

int	validate(t_map *map, double new_x, double new_y)
{
	int	moved;

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

	new_x = map->player.pos_x + map->player.dir_x * MOVESPEED;
	new_y = map->player.pos_y + map->player.dir_y * MOVESPEED;
	return (validate(map, new_x, new_y));
}

int	backwards(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player.pos_x - map->player.dir_x * MOVESPEED;
	new_y = map->player.pos_y - map->player.dir_y * MOVESPEED;
	return (validate(map, new_x, new_y));
}

int	left(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player.pos_x + map->player.dir_y * MOVESPEED;
	new_y = map->player.pos_y - map->player.dir_x * MOVESPEED;
	return (validate(map, new_x, new_y));
}

int	right(t_map *map)
{
	double	new_x;
	double	new_y;

	new_x = map->player.pos_x - map->player.dir_y * MOVESPEED;
	new_y = map->player.pos_y + map->player.dir_x * MOVESPEED;
	return (validate(map, new_x, new_y));
}

int	move_player(t_map *map)
{
	int	moved;

	moved = 0;
	if (map->player.move_y == 1)
		moved += forward(map);
	if (map->player.move_y == -1)
		moved += backwards(map);
	if (map->player.move_x == -1)
		moved += left(map);
	if (map->player.move_x == 1)
		moved += right(map);
	if (map->player.rotate != 0)
		moved += rotate_player(map, 0);

	return (moved);
}

int	render(t_map *map)
{
	map->player.moved += move_player(map);
	render_images(map);
	return (0);
}

