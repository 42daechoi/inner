/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:08:47 by daechoi           #+#    #+#             */
/*   Updated: 2022/06/20 15:53:49 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(t_pipe p, int fd[2], char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		std_in(p.file[0]);
		close(fd[0]);
		dup2(fd[1], 1);
		if (execve(p.path_cmd0, p.cmd0, envp) == -1)
			return (-1);
	}
	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		std_out(p.file[1]);
		if (execve(p.path_cmd1, p.cmd1, envp) == -1)
			return (-1);
	}
	close(fd[0]);
	close(fd[1]);
	while (wait(0) != -1)
		;
	return (0);
}
