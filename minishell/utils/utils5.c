/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:42:30 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/19 16:28:13 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wait_fork(void)
{
	int	status;

	status = 0;
	while (wait(&status) != -1)
		;
	if (WIFEXITED(status))
		g_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
		{
			printf("^C\n");
			g_status = WTERMSIG(status) + 128;
		}
		else if (WTERMSIG(status) == SIGQUIT)
		{
			printf("^\\Quit: 3\n");
			g_status = WTERMSIG(status) + 128;
		}
	}
}

char	**envpcopy(char **envp)
{
	int		i;
	char	**copy_envp;

	i = 0;
	while (envp[i])
		i++;
	copy_envp = (char **)ft_malloc(sizeof(char *) * (i + 100));
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "OLDPWD", 6) == 0)
		{
			copy_envp[i] = (char *)ft_malloc(sizeof(char) * 7);
			ft_strcpy(copy_envp[i], "OLDPWD");
		}
		else
		{
			copy_envp[i] = \
			(char *)ft_malloc(sizeof(char) * (ft_strlen(envp[i]) + 1));
			ft_strcpy(copy_envp[i], envp[i]);
		}
		i++;
	}
	copy_envp[i] = NULL;
	return (copy_envp);
}

int	envp_len(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

char	*get_home(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "HOME", 4) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

void	perror_exit(char *str)
{
	perror(str);
	exit(127);
}
