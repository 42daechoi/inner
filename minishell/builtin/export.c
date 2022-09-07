/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:34:31 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/12 18:49:54 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	print_export(char **envp)
{
	int		len;
	int		i;
	int		j;
	char	*temp;

	len = envp_len(envp);
	i = 0;
	j = 0;
	while (i < len)
	{
		j = 1;
		while (j < len)
		{
			if (ft_strcmp(envp[j - 1], envp[j]) > 0)
			{
				temp = envp[j - 1];
				envp[j - 1] = envp[j];
				envp[j] = temp;
			}
			j++;
		}
		i++;
	}
	print_arr(envp);
	return (1);
}

int	find_same(char *str, char **envp)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strdup(str);
	while (temp[i] != '\0' && temp[i] != '=')
		i++;
	temp[i] = '\0';
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(temp, envp[i], ft_strlen(temp)) == 0)
		{
			ft_free(temp);
			temp = envp[i];
			envp[i] = ft_strdup(str);
			ft_free(temp);
			return (1);
		}
		i++;
	}
	ft_free(temp);
	return (0);
}

char	**envpcopy_expoort(char **envp)
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
		copy_envp[i] = \
		(char *)ft_malloc(sizeof(char) * (ft_strlen(envp[i]) + 1));
		ft_strcpy(copy_envp[i], envp[i]);
		i++;
	}
	copy_envp[i] = NULL;
	return (copy_envp);
}

void	add_env(t_token token, char **envp, int i)
{
	char	*add;
	int		j;

	j = 0;
	add = ft_strdup(token.option[i]);
	while (envp[j])
		j++;
	envp[j + 1] = NULL;
	while (j > 0)
	{
		envp[j] = envp[j - 1];
		j--;
	}
	envp[++j] = add;
}

int	do_export(t_token token, char **envp, int flag)
{
	char	**copy_envp;
	int		i;

	copy_envp = envpcopy_expoort(envp);
	i = 1;
	if (token.option[1] == NULL)
	{
		print_export(copy_envp);
		return (free_all_envp(copy_envp, flag));
	}
	while (token.option[i])
	{
		if (find_same(token.option[i], envp))
			;
		else
			add_env(token, envp, i);
		i++;
	}
	g_status = 0;
	return (free_all_envp(copy_envp, flag));
}
