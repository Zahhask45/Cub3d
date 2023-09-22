/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:53:32 by brumarti          #+#    #+#             */
/*   Updated: 2023/09/22 17:08:40 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	valid_border(char c)
{
	if (c != ' ' && c != '1' && c != '\t')
	{
		ft_putstr_fd("Error\nInvalid char!\n", STDERR_FILENO);
		exit(1);
	}
}

void	validate_map(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			c = map->map[i][j];
			if (i == 0 || i == map->n_lines - 1 || j == 0 || j == (int)ft_strlen(map->map[i] - 1)) 
				valid_border(c);
			else if (c != '1' && c != '0' && c != ' ' && c != map->p_dir)
			{
				ft_putstr_fd("Error\nInvalid char!\n", STDERR_FILENO);
				exit(1);
			}
			j++;
		}
		i++;
	}
	if (map->f_rgb[0] == -1 || map->c_rgb[0] == -1)
	{
		ft_putstr_fd("Error\nMissing RGB\n", STDERR_FILENO);
		exit(1);
	}
}
