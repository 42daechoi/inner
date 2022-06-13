/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:08:47 by daechoi           #+#    #+#             */
/*   Updated: 2022/06/13 20:28:57 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(t_pipe p, int fd[2], char **envp, pid_t pid)
{
	if (pid > 0)
	{
		waitpid(pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], 0);
		std_out(p.file[1]);
		if (execve(p.path_cmd1, p.cmd1, envp) == -1)
			ft_printerr("execve error");
	}
	else if (pid == 0)
	{
		std_in(p.file[0]);
		close(fd[0]);
		dup2(fd[1], 1);
		if (execve(p.path_cmd0, p.cmd0, envp) == -1)
			ft_printerr("execve error");
	}
	else
		ft_printerr("fork error");
	return (-1);
}
