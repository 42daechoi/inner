/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:08:30 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/12 18:49:47 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_eq_exist(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == '=')
			return (1);
	return (0);
}

int	print_env(char **envp)
{
	int	i;

	g_status = 0;
	i = 0;
	while (envp[i])
	{
		if (is_eq_exist(envp[i]))
			printf("%s\n", envp[i]);
		i++;
	}
	return (1);
}
