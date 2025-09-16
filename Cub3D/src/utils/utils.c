/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:31:20 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/11/08 13:57:31 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_iswspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_isvalidc(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == 'F' || c == 'C' || c == '1' || ft_iswspace(c))
		return (1);
	return (0);
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (j < (int)ft_strlen(map->map[i]))
		{
			ft_putchar_fd(map->map[i][j], 0);
			j++;
		}
		ft_putchar_fd('\n', 0);
		i++;
	}
}

void	error_msg(char *msg)
{
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	ft_putstr_fd(msg, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	exit(1);
}

int	last_char(char *str, char c)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (str[i])
	{
		if (str[i] == c)
			pos = i;
		i++;
	}
	return (pos + 1);
}
