/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:07:53 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/11/08 14:59:10 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	close_win(t_map *map)
{
	ft_putendl_fd("Exiting", 1);
	free(map->img[NORTH].path);
	free(map->img[SOUTH].path);
	free(map->img[WEST].path);
	free(map->img[EAST].path);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	free_tab((void **)map->text);
	free_tab((void **)map->map);
	free_tab((void **)map->text_pix);
	exit(EXIT_SUCCESS);
}

int	keyhooks_release(int key, t_map *map)
{
	if (!(map->mlx))
		return (0);
	if (key == ESC)
		close_win(map);
	if (key == ARROW_LEFT && map->player.rotate <= 1)
		map->player.rotate = 0;
	if (key == ARROW_RIGHT && map->player.rotate >= -1)
		map->player.rotate = 0;
	if (key == W_BUTTON && map->player.move_y == 1)
		map->player.move_y = 0;
	if (key == A_BUTTON && map->player.move_x == -1)
		map->player.move_x = 0;
	if (key == S_BUTTON && map->player.move_y == -1)
		map->player.move_y += 1;
	if (key == D_BUTTON && map->player.move_x == 1)
		map->player.move_x -= 1;
	return (0);
}

int	keyhooks_press(int key, t_map *map)
{
	if (!(map->mlx))
		return (0);
	if (key == ESC)
		close_win(map);
	if (key == ARROW_LEFT)
		map->player.rotate -= 1;
	if (key == ARROW_RIGHT)
		map->player.rotate += 1;
	if (key == W_BUTTON)
		map->player.move_y = 1;
	if (key == A_BUTTON)
		map->player.move_x = -1;
	if (key == S_BUTTON)
		map->player.move_y = -1;
	if (key == D_BUTTON)
		map->player.move_x = 1;
	return (0);
}
