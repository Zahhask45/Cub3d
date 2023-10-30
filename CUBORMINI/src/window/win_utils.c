/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:07:53 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/30 13:51:54 by jodos-sa         ###   ########.fr       */
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
	if (key == 0xff1b) //* ESC button
		close_win(map);
	if (key == 0xff51 && map->player.rotate <= 1) //* ARROW LEFT button
		map->player.rotate = 0;
	if (key == 0xff53 && map->player.rotate >= -1) //* ARROW RIGHT button
		map->player.rotate = 0;
	if (key == 0x0077 && map->player.move_y == 1) //* W button
		map->player.move_y = 0;
	if (key == 0x0061 && map->player.move_x == -1) //* A button
		map->player.move_x = 0;
	if (key == 0x0073 && map->player.move_y == -1) //* S button
		map->player.move_y += 1;
	if (key == 0x0064 && map->player.move_x == 1) //* D button
		map->player.move_x -= 1;
	return (0);
}

int	keyhooks_press(int key, t_map *map)
{
	if (!(map->mlx))
		return (0);
	if (key == 0xff1b) //* ESC button
		close_win(map);
	if (key == 0xff51) //* ARROW LEFT button
		map->player.rotate -= 1;
	if (key == 0xff53) //* ARROW RIGHT button
		map->player.rotate += 1;
	if (key == 0x0077) //* W button
		map->player.move_y = 1;
	if (key == 0x0061) //* A button
		map->player.move_x = -1;
	if (key == 0x0073) //* S button
		map->player.move_y = -1;
	if (key == 0x0064) //* D button
		map->player.move_x = 1;
	return (0);
}