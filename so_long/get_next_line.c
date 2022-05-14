/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:48:25 by daechoi           #+#    #+#             */
/*   Updated: 2022/04/19 17:34:24 by daechoi          ###   ########.fr       */
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
	static char	*line;
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	int			rdsize;

	if (fd > OPEN_MAX || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	rdsize = read(fd, buff, BUFFER_SIZE);
	while (rdsize > 0)
	{
		buff[rdsize] = '\0';
		if (!line)
			line = ft_strdup("");
		if (!line)
			return (NULL);
		temp = line;
		line = ft_strjoin(temp, buff);
		free(temp);
		if (!line)
			return (NULL);
		if (ft_check_newline(line) > -1)
			break ;
		rdsize = read(fd, buff, BUFFER_SIZE);
	}
	return (ft_take_newline(&line, rdsize));
}