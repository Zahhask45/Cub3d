/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:07:53 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/09/20 16:53:20 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	keyhooks(int key, t_map *map)
{
	if (!(map->mlx))
		return (0);
	if (key == 0xff1b)
	{
		ft_putendl_fd("Exiting", 1);
		close_win(map);
		//free_all(map);
	}
	return (0);
}