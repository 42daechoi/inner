/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:19:10 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/23 19:25:46 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	signal_execve(t_token *token, int index, char **envp)
{
	return (execve(token[index].cmd, token[index].option, envp));
}

void	wait_and_signal(void)
{
	signal_ignore();
	wait_fork();
	signal_shell();
}

int	change_path(t_token *token, int index)
{
	char	*temp;

	temp = token[index].cmd;
	if (temp)
	{
		token[index].cmd = ft_strdup(token[index].option[0]);
		ft_free(temp);
		temp = NULL;
	}
	return (1);
}

int	return_home(char *home)
{
	if (!home)
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		g_status = 1;
		return (1);
	}
	else
	{
		chdir(home);
		g_status = 0;
		return (0);
	}
}

int	return_not_home(t_token token)
{
	if (chdir(token.option[1]) < 0)
	{
		perror(token.option[1]);
		g_status = 1;
		return (1);
	}
	else
	{
		g_status = 0;
		return (0);
	}
}
