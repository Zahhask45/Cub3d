/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:02:56 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/10/27 16:09:45 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char	*ft_read_to(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchrr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str[fd] = ft_read_to(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_new_left(left_str[fd]);
	return (line);
}
/*
int	main(void)
{
	char	*line;
	int		i;
	int		equal;
	//int		fd1;
	int		fd2;
	int		fd3;
	//fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/banana.txt", O_RDONLY);
	fd3 = open("tests/never.txt", O_RDONLY);
	i = 1;
	while (i < 54)
	{
		line = get_next_line(fd2);
		printf("%s \n", line);
		free(line);
		i++;
	}
	printf("\n");
	close(fd2);
	equal = 210;
	while (equal--)
		printf("=");
	printf("\n\n\n");
	i = 1;
	while (i < 55)
	{
		line = get_next_line(fd3);
		printf("%s \n", line);
		free(line);
		i++;
	}
	close(fd3);
	return (0);
}*/
