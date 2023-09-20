/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:24:06 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/09/18 14:47:19 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	close_win(t_win *win)
{
	mlx_destroy_image(win->mlx, win->img);
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	free(win);
	exit(EXIT_SUCCESS);
}

void	make_windows(t_win *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "BANANA");
	win->img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	/* win->addr = mlx_get_data_addr(win->img, &(win->bits_per_pixel),
			&(win->line_length),
			&(win->endian));
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	print_xy(win);
	mlx_hook(win->win, 2, 1L << 0, keyhooks, win);
	mlx_mouse_hook(win->win, mousehook, win);
	mlx_hook(win->win, 6, 0, motion, win); */
	mlx_hook(win->win, 17, 0, close_win, win);
	mlx_loop(win->mlx);
}

int main()
{
	t_win	*win;

	win = ft_memalloc(sizeof(t_win *));
	make_windows(win);
	return (0);
}
