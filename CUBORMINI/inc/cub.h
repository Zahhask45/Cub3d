/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:27:31 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/09/20 17:27:40 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define HEIGHT 1080
# define WIDTH 1920

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img
{
	void	*mlx_img;
	char	*path;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
	t_img	img[5];

	int		rgb_floor[3];
	int		rgb_ceil[3];

}			t_map;


//* UTILS

void	*ft_memalloc(size_t size);



void	make_windows(t_map *map);
int		close_win(t_map *map);
int		keyhooks(int key, t_map *map);

#endif