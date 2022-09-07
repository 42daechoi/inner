/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:08:36 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/18 18:22:54 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	start_fork(t_token *token, char **envp)
{
	pid_t	pid;
	int		len;
	int		i;

	i = 0;
	signal_heredoc();
	len = token_len(token);
	while (i < len)
	{
		if (i != len - 1)
			pipe(token[i].fd);
		pid = fork();
		if (pid == 0)
		{
			parallel_start(token, envp, i, len);
			exit(1);
		}
		if (i > 0)
		{
			close(token[i - 1].fd[0]);
			close(token[i - 1].fd[1]);
		}
		i++;
	}
	wait_and_signal();
}

void	parallel_start(t_token *token, char **envp, int i, int len)
{
	if (i == 0)
		index_zero(token, envp, i);
	else if (i == len - 1)
		index_last(token, envp, i);
	else
		index_normal(token, envp, i);
}

int	index_zero(t_token *token, char **envp, int index)
{
	int	infile_fd;
	int	outfile_fd;

	infile_fd = open_infile(token, index);
	if (infile_fd == 0)
		return (0);
	if (infile_fd > 0)
		ft_stdin(token, index, infile_fd);
	outfile_fd = open_outfile(token, index);
	if (outfile_fd > 0)
		ft_stdout(outfile_fd);
	else
		set_pipe_entry(token[index].fd);
	if (do_builtin(token, envp, index) == 1)
		return (1);
	infile_fd = vaild_cmd_path(token, envp, index);
	if (!infile_fd)
		return (print_err(token[index].option[0], "command not found\n"));
	else if (infile_fd > 1)
		return (1);
	else if (signal_execve(token, index, envp) < 0)
		perror_exit(token[index].cmd);
	return (1);
}

int	index_normal(t_token *token, char **envp, int index)
{
	int	infile_fd;
	int	outfile_fd;

	infile_fd = open_infile(token, index);
	if (infile_fd < 0)
		set_pipe_exit(token[index - 1].fd);
	else if (infile_fd >= 0)
	{
		close(token[index - 1].fd[0]);
		close(token[index - 1].fd[1]);
		ft_stdin(token, index, infile_fd);
		if (infile_fd == 0)
			return (0);
	}
	outfile_fd = open_outfile(token, index);
	set_pipe_entry(token[index].fd);
	if (outfile_fd > 0)
		ft_stdout(outfile_fd);
	if (do_builtin(token, envp, index) == 1)
		return (1);
	return (do_execve(token, index, envp));
}

int	index_last(t_token *token, char **envp, int index)
{
	int	infile_fd;
	int	outfile_fd;

	infile_fd = open_infile(token, index);
	if (infile_fd < 0)
		set_pipe_exit(token[index - 1].fd);
	else if (infile_fd >= 0)
	{
		close(token[index - 1].fd[0]);
		close(token[index - 1].fd[1]);
		ft_stdin(token, index, infile_fd);
		if (infile_fd == 0)
			return (0);
	}
	outfile_fd = open_outfile(token, index);
	if (outfile_fd > 0)
		ft_stdout(outfile_fd);
	if (do_builtin(token, envp, index) == 1)
		return (1);
	return (do_execve(token, index, envp));
}
