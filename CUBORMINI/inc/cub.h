/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:27:31 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/09/25 15:54:49 by brumarti         ###   ########.fr       */
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

	char	**map;
	int		n_cols;
	int		n_lines;
	int		p_pos[2];
	int		f_rgb[3];
	int		c_rgb[3];
	char	p_dir;

}			t_map;

//* UTILS
void	*ft_memalloc(size_t size);
int		ft_iswspace(char c);
int		ft_isvalidc(char c);
void	print_map(t_map *map);
void	error_msg(char *msg);

//* CREATE_MAP
void	create_map(char *path_map, t_map *map);

//* INIT_TEXTURES
void	init_textures(t_map *map, int fd);
void	make_windows(t_map *map);
int		close_win(t_map *map);
int		keyhooks(int key, t_map *map);

//* CHECK_VALID
void	validate_map(t_map *map);

#endif