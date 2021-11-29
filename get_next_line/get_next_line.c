/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:48:25 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/29 20:11:38 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	ft_check_newline(char *line)
{
	int	i;
	
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_take_newline(char *line, int pos)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc((pos + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < pos)
	{
		res[i] = line[i];
		i++;
	}
	res[pos] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	line[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			rdsize;
	int			pos;

	if (fd > OPEN_MAX || fd < 0)
		return (NULL);
	while (rdsize = read(fd, buff, BUFFER_SIZE) > 0)
	{
		buff[rdsize] == '\0';
		line[fd] = ft_strjoin(line[fd], buff);
		pos = ft_check_newline(line[fd]);
		if (pos > 0)
			return (ft_take_newline(line[fd], pos));
	}
	return (line);
}