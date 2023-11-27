/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:27:31 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/11/27 15:44:15 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

# define HEIGHT 1000
# define WIDTH 1920
# define MOVESPEED 0.1
# define ROTATION_SPEED 0.08
# define ROTATION_MOUSE 0.03
# define ESC 0xff1b
# define ARROW_LEFT 0xff51
# define ARROW_RIGHT 0xff53
# define W_BUTTON 0x0077
# define A_BUTTON 0x0061
# define S_BUTTON 0x0073
# define D_BUTTON 0x0064

enum e_texture_index
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

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
	int		view_dis;
	int		tile_size;

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
	int			fd;
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
void	free_tab(void **tab);
int		last_char(char *str, char c);
bool	valid_map_coord(int coord, int size);
int		get_mini_offset(t_mini *minimap, int map_size, int pos);
int		get_mini_offset(t_mini *minimap, int map_size, int pos);
bool	valid_map_coord(int coord, int size);
void	clean_map(t_map *map);
void	finish_gnl(char *line, int fd);
void	clean_msg(t_map *map, char *line, char *msg, int gnl);
void	error_dup(t_map *map, char *line);

//* CREATE_MAP
void	create_map(char *path_map, t_map *map);
int		create_trgb(int t, int red, int green, int blue);
void	init_rgb(char *line, t_map *map, int j);
void	get_textures(char *line, t_map *map, char c, int j);

//* INIT_TEXTURES
void	init_textures(t_map *map, int fd);
void	make_windows(t_map *map);
int		close_win(t_map *map);
int		keyhooks_press(int key, t_map *map);
void	init_texture_img(t_map *map, t_img *image, char *path);
void	start_text(t_map *map);
void	init_img(t_map *map, t_img *image, int width, int height);

//* MINIMAP
void	draw_minimap(t_mini *minimap);
void	init_minimap(t_map *map);

//* INIT INFO
void	init_clean_img(t_img *img);
void	init_textinfo(t_text *texture);
void	init_colors(t_map *map);
void	init_player(t_player *player);
void	init_all(t_map *map);
void	init_ray_info(int x, t_ray *ray, t_player *player);
void	init_ray(t_ray *ray);

//* TEXTURE CONFIGURATION
void	textures_pixel(t_map *map);
void	get_index(t_map *map, t_ray *ray);
void	update_text(t_map *map, t_ray *ray, t_text *texture, int x);

//* INPUT
int		keyhooks_release(int key, t_map *map);
void	input(t_map *map);

//* RENDER
void	render_images(t_map *map);
int		render(t_map *map);

//! NOT THE REAL PLACE TO PUT THIS ONE
void	set_image(t_img *image, int x, int y, int colour);
int		rotate_player(t_map *map, int mode);
void	p_pos(t_map *map);
void	rgb_text(t_map *map, char *line, int j);
void	get_size(char *path_map, t_map *map);
int		validate(t_map *map, double new_x, double new_y);
int		ray(t_player *player, t_map *map);
void	frame(t_map *map);

//* DDA
void	dda(t_ray *ray, t_player *player);
void	do_dda(t_map *map, t_ray *ray);

//* MOVEMENTS
int		right(t_map *map);
int		left(t_map *map);
int		forward(t_map *map);
int		backwards(t_map *map);

//* CHECK_VALID
void	validate_map(t_map *map);

#endif