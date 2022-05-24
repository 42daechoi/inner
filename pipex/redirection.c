/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:57:50 by daechoi           #+#    #+#             */
/*   Updated: 2022/05/24 20:13:01 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	redirect_in(char *path_cmd)
{
	int	fd;

	fd = open(path_cmd, O_RDONLY);
	if (fd < 0)
	{
		perror(path_cmd);
		return (0);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (1);
}

int	redirect_out(char *path_cmd)
{
	int	fd;
	fd = open(path_cmd, O_CREAT | O_RDWR | O_TRUNC);
	if (fd < 0)
	{
		perror(path_cmd);
		return (0);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (1);
}

