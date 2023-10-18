/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:27:31 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/18 15:39:29 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define HEIGHT 1000
# define WIDTH 1920
# define MOVESPEED 0.1
# define ROTATION_SPEED 0.08
# define ROTATION_MOUSE 0.03

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
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
	double	step;
	double	pos;
	int		x;
	int		y;
}			t_text;

typedef struct s_mini
{
	char	**map;
	t_img	*img;
	int		size;
	int		off_x;
	int		off_y;
	int		view_dis; // 6 Tiles from where the player is
	int		tile_size; // 6 pixels

}			t_mini;


typedef struct s_map
{
	void		*mlx;
	void		*mlx_win;
	t_img		img[4];
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
int		ft_isvalidc(char c);
void	print_map(t_map *map);
void	error_msg(char *msg);
int		last_char(char *str, char c);

//* CREATE_MAP
void	create_map(char *path_map, t_map *map);
int		create_trgb(int t, int red, int green, int blue);

//* INIT_TEXTURES
void	init_textures(t_map *map, int fd);
void	make_windows(t_map *map);
int		close_win(t_map *map);
int		keyhooks_press(int key, t_map *map);

//* MINIMAP
void	init_minimap(t_map *map); 


//* INIT INFO
void	init_clean_img(t_img *img);
void	init_textinfo(t_text *texture);
void	init_colors(t_map *map);
void	init_player(t_player *player);
void	init_all(t_map *map);

//* INIT TEXTURES
void	init_texture_img(t_map *map, t_img *image, char *path);
void	start_text(t_map *map);

//* INPUT
int		keyhooks_release(int key, t_map *map);
void	input(t_map *map);

//* RENDER
void	render_images(t_map *map);
int		render(t_map *map);


//! NOT THE REAL PLACE TO PUT THIS ONE
void	set_image(t_img *image, int x, int y, int colour);
int		rotate_player(t_map *map, int mode);


//* CHECK_VALID
void	validate_map(t_map *map);

#endif