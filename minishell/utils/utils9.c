/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:48:05 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/24 15:48:06 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_undefined(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (0);
		i++;
	}
	printf("%s\n", str);
	return (1);
}

void	print_defined(char **envp, int i, int j, int flag)
{
	while (envp[i][j] != '\0')
	{
		if (envp[i][j] != '=')
			printf("%c", envp[i][j++]);
		else if (envp[i][j] == '=')
		{
			flag = 1;
			printf("%c\"", envp[i][j++]);
		}
		if (envp[i][j] == '\0' && flag == 1)
			printf("\"\n");
	}
}

void	print_arr(char **envp)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	while (envp[i])
	{
		printf("declare -x ");
		if (is_undefined(envp[i]))
			;
		else
		{
			j = 0;
			print_defined(envp, i, j, flag);
		}
		i++;
	}
	g_status = 0;
}
