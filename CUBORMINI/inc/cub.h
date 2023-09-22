/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:27:31 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/09/22 17:26:48 by jodos-sa         ###   ########.fr       */
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
	t_img	minimap;

	char	**map;
	int		n_cols;
	int		n_lines;
	int		p_pos[2];
	int		f_rgb[3];
	int		c_rgb[3];
	char	p_dir;

}			t_map;

//* UTILS

int		is_valid_char(char c, char *play);
void	*ft_memalloc(size_t size);
int		ft_iswspace(char c);

//* CREATE_MAP
void	create_map(char *path_map, t_map *map);
int		create_trgb(int t, int red, int green, int blue);

//* INIT_TEXTURES
void	init_textures(t_map *map, int fd);
void	make_windows(t_map *map);
int		close_win(t_map *map);
int		keyhooks(int key, t_map *map);

//* MINIMAP
void	init_minimap(t_map *map); 

#endif