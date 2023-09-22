/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:31:20 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/09/22 17:26:32 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_valid_char(char c, char *play)
{
	int	i;

	i = 0;
	while (play[i])
	{
		if (c == play[i])
			return (1);
		i++;
	}
	return (0);
}

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

int	ft_iswspace(char c)
{
	if (c < 33 || c > 126)
		return (1);
	return (0);
}
