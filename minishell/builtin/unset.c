/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:07:54 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/12 18:50:01 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	var_len(char *var)
{
	int	i;

	i = 0;
	while (var[i])
		i++;
	return (i);
}

int	search_same_index(t_token token, char **envp, int index)
{
	int	i;
	int	len;

	i = 0;
	len = var_len(token.option[index]);
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], token.option[index], len))
			return (i);
		i++;
	}
	return (-1);
}

int	print_unset(t_token token, char **envp)
{
	int	index;
	int	i;

	i = 1;
	if (token.option[1] == NULL)
		return (0);
	while (token.option[i])
	{
		index = search_same_index(token, envp, i);
		if (index != -1)
		{
			ft_free(envp[index]);
			envp[index] = envp[index + 1];
			index++;
			while (envp[index])
			{
				envp[index] = envp[index + 1];
				index++;
			}
			envp[index] = NULL;
		}
		i++;
	}
	g_status = 0;
	return (1);
}
