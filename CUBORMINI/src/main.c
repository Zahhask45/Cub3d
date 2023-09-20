/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:24:06 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/09/20 17:28:22 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int main()
{
	t_map	map;


	map.rgb_floor[0] = 164;
	map.rgb_floor[1] = 169;
	map.rgb_floor[2] = 20;
	map.rgb_ceil[0] = 153;
	map.rgb_ceil[1] = 204;
	map.rgb_ceil[2] = 255;
	//map = ft_memalloc(sizeof(t_map *));
	make_windows(&map);
	return (0);
}
