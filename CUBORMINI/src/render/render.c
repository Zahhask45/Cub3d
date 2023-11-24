/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:53:44 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/11/08 13:54:07 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
