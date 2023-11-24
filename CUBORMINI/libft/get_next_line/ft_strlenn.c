/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:58:17 by brumarti          #+#    #+#             */
/*   Updated: 2023/11/08 15:07:54 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlenn(const char *s)
{
	size_t	length;

	length = 0;
	if (!s)
		return (length);
	while (s[length])
		length++;
	return (length);
}
