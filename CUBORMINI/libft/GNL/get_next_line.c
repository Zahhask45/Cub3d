/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:02:56 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/08/05 14:40:45 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
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
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left(left_str);
	return (line);
}

int	main(void)
{
	char	*line;
	int		i;
	int		equal;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test.txt", O_RDONLY);
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
	while (i < 60)
	{
		line = get_next_line(fd3);
		printf("%s \n", line);
		free(line);
		i++;
	}
	close(fd3);
	return (0);
}
