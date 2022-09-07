/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:17:02 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/17 21:37:28 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	free_and_return(char *temp, char **path)
{
	ft_free(temp);
	temp = NULL;
	free_path(path);
	return (0);
}

int	do_builtin(t_token *token, char **envp, int index)
{
	if (ft_strcmp(token[index].cmd, "pwd") == 0)
		return (print_pwd());
	else if (ft_strcmp(token[index].option[0], "export") == 0)
		return (do_export(token[index], envp, 0));
	else if (ft_strcmp(token[index].option[0], "env") == 0)
		return (print_env(envp));
	else if (ft_strcmp(token[index].option[0], "cd") == 0)
		return (change_dir(token[index], envp));
	else if (ft_strcmp(token[index].option[0], "unset") == 0)
		return (print_unset(token[index], envp));
	else if (ft_strcmp(token[index].option[0], "echo") == 0)
		return (print_echo(token[index]));
	else if (ft_strcmp(token[index].option[0], "exit") == 0)
		return (print_exit(token[index]));
	return (0);
}

void	befor_make_full(char *temp, char **path, t_token *token, int index)
{
	ft_free(temp);
	temp = NULL;
	free_path(path);
	ft_free(token[index].cmd);
	token[index].cmd = NULL;
}

int	make_full_path_return(t_token *token, int index, char **envp)
{
	char	**path;
	char	*temp;
	char	*full_path;
	int		i;

	i = 0;
	path = parsing_path(envp);
	if (!path)
		return (1);
	temp = ft_strjoin("/", token[index].option[0]);
	while (path[i])
	{
		full_path = ft_strjoin(path[i], temp);
		if (open(full_path, O_RDONLY) > 0)
		{
			befor_make_full(temp, path, token, index);
			token[index].cmd = full_path;
			return (1);
		}
		ft_free(full_path);
		i++;
	}
	return (free_and_return(temp, path));
}

int	do_execve(t_token *token, int index, char **envp)
{
	int	temp;

	temp = vaild_cmd_path(token, envp, index);
	if (!temp)
	{
		g_status = 1;
		return (print_err(token[index].option[0], "command not found\n"));
	}
	else if (temp > 1)
		return (1);
	else if (signal_execve(token, index, envp) < 0)
		perror(token[index].cmd);
	return (1);
}
