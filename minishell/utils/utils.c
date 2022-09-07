/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:04:52 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/12 18:50:10 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	file_len(char **file)
{
	int	i;

	if (!file)
		return (0);
	i = 0;
	while (file[i])
		i++;
	return (i);
}

void	close_and_free(t_token *token, int *fd, int index)
{
	int	j;

	j = 0;
	if (token[index].infile == NULL)
	{
		ft_free(fd);
		fd = 0;
		return ;
	}
	while (fd[j] < file_len(token[index].infile) - 1)
		close(fd[j++]);
	ft_free(fd);
	fd = 0;
}

char	**parsing_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (!envp[i])
		return (NULL);
	path = ft_split(envp[i] + 5, ":");
	if (!path)
		return (NULL);
	return (path);
}

int	token_len(t_token *token)
{
	int		i;

	i = 0;
	while (token[i].str)
		i++;
	return (i);
}

int	vaild_cmd_path(t_token *token, char **envp, int index)
{
	if (token[index].option[0][0] == '\0')
	{
		printf("");
		exit(0);
	}
	if (ft_strcmp(token[index].option[0], "..") == 0)
		return (0);
	if (ft_strcmp(token[index].option[0], ".") == 0)
	{
		token[index].cmd = ".";
		return (1);
	}
	if (ft_strncmp(token[index].option[0], "./", 2) == 0 \
		|| ft_strncmp(token[index].option[0], "/", 1) == 0 \
		|| token[index].option[0][ft_strlen(token[index].option[0]) - 1] == '/')
	{
		if (opendir(token[index].option[0]) != NULL)
			return (printf("%s: is a directory\n", token[index].option[0]));
		else
			return (change_path(token, index));
	}
	return (make_full_path_return(token, index, envp));
}
