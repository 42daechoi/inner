/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:06:49 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/18 20:25:19 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	print_err(char *cmd, char *str)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	exit(127);
	return (0);
}

void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		ft_free(path[i]);
		path[i++] = NULL;
	}
}

int	open_outfile(t_token *token, int index)
{
	int	fd;
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (token[index].outfile == NULL)
		return (-1);
	while (token[index].outfile[len])
		len++;
	while (i < len)
	{
		if (token[index].append_flag[i] == 1)
			fd = open(token[index].outfile[i++], \
			O_RDWR | O_CREAT | O_APPEND, 0644);
		else
			fd = open(token[index].outfile[i++], \
			O_RDWR | O_CREAT | O_TRUNC, 0644);
	}
	return (fd);
}

int	infile_or_lastdoc(t_token *token, int index, int i)
{
	int	fd;

	if (token[index].last_doc == NULL)
		return (i);
	fd = open(token[index].last_doc, O_RDONLY);
	close(i);
	if (!token[index].option[0])
	{
		close(fd);
		unlink(token[index].last_doc);
		open_outfile(token, index);
		exit(0);
	}
	return (fd);
}

int	open_infile(t_token *token, int index)
{
	int	i;
	int	*fd;
	int	j;

	if (token[index].infile == NULL && token[index].last_doc == NULL)
		return (-1);
	i = 0;
	fd = (int *)ft_malloc(sizeof(int) * file_len(token[index].infile));
	while (token[index].infile != NULL && token[index].infile[i])
	{
		fd[i] = open(token[index].infile[i], O_RDONLY);
		if (fd[i] < 0)
		{
			perror(token[index].infile[i]);
			j = 0;
			while (j < i)
				close(fd[j++]);
			return (0);
		}
		i++;
	}
	if (token[index].infile != NULL)
		i = fd[file_len(token[index].infile) - 1];
	close_and_free(token, fd, index);
	return (infile_or_lastdoc(token, index, i));
}
