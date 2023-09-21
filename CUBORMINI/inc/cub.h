/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:27:31 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/09/21 15:08:06 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define HEIGHT 700
# define WIDTH 900

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_win;

typedef struct s_map
{
	char	**map;
	int		n_cols;
	int		n_lines;
	int		p_pos[2];
	char	p_dir;
	int		f_rgb[3];
	int		c_rgb[3];
	char	*n_path;
	char	*s_path;
	char	*w_path;
	char	*e_path;

}			t_map;



//* UTILS

void	*ft_memalloc(size_t size);
int		ft_iswspace(char c);

//* CREATE_MAP
void	create_map(char *path_map);

//* INIT_TEXTURES
void	init_textures(t_map *map, int fd);

#endif