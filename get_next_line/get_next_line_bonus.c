/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:26:11 by daechoi           #+#    #+#             */
/*   Updated: 2021/12/08 15:28:18 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_take_newline(char **line, int rdsize)
{
	char	*res;
	char	*temp;
	int		pos;

	if (!line || !*line || rdsize < 0)
		return (NULL);
	pos = ft_check_newline(*line);
	if (pos > -1)
	{
		res = ft_substr(*line, 0, pos + 1);
		temp = ft_substr(*line, pos + 1, ft_strlen(*line) - (pos + 1));
		free(*line);
		*line = temp;
		if (**line != '\0')
			return (res);
	}
	else
		res = ft_strdup(*line);
	free(*line);
	*line = NULL;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	int			rdsize;

	if (fd > OPEN_MAX || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	rdsize = read(fd, buff, BUFFER_SIZE);
	while (rdsize > 0)
	{
		buff[rdsize] = '\0';
		if (!line[fd])
			line[fd] = ft_strdup("");
		if (!line[fd])
			return (NULL);
		temp = line[fd];
		line[fd] = ft_strjoin(temp, buff);
		free(temp);
		if (!line[fd])
			return (NULL);
		if (ft_check_newline(line[fd]) > -1)
			break ;
		rdsize = read(fd, buff, BUFFER_SIZE);
	}
	return (ft_take_newline(&line[fd], rdsize));
}
