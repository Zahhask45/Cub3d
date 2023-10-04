/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:27:31 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/09/30 14:49:41 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define HEIGHT 1080
# define WIDTH 1920
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

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
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_ray
{
	double	cam_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sid_dis_x;
	double	sid_dis_y;
	double	delta_dis_x;
	double	delta_dis_y;
	double	wall_x;
	double	wall_dis;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}			t_ray;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		moved;
	int		move_x;
	int		move_y;
	int		rotate;
}			t_player;

typedef struct s_text
{
	int		size;
	int		index;
	int		step;
	int		pos;
	int		x;
	int		y;
}			t_text;



typedef struct s_map
{
	void		*mlx;
	void		*mlx_win;
	t_img		img[5];
	t_img		minimap;

	char		**map;
	int			n_cols;
	int			n_lines;
	int			f_rgb[3];
	int			c_rgb[3];
	int			c_hex;
	int			f_hex;
	int			text_index;
	int			text_x;
	int			text_y;



	int			p_pos[2];
	char		p_dir;


	int			**text_pix;
	int			**text;
	
	t_ray		ray;
	t_player	player;
	t_text		texture;
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