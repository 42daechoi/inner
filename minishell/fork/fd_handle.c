/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:49:54 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/12 18:51:01 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_stdin(t_token *token, int index, int fd)
{
	dup2(fd, STDIN_FILENO);
	close(fd);
	if (token[index].last_doc != NULL)
		unlink(token[index].last_doc);
}

void	set_pipe_entry(int *fildes)
{
	dup2(fildes[1], 1);
	close(fildes[0]);
}

void	set_pipe_exit(int *fildes)
{
	dup2(fildes[0], 0);
	close(fildes[1]);
}

void	ft_stdout(int fd)
{
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
