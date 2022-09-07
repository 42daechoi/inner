/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:43:32 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/12 18:49:51 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_all_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i++]))
			return (0);
	}
	return (1);
}

void	print_error(void)
{
	printf("exit\nexit: a3rwefd: numeric argument required\n");
	g_status = 1;
	exit(-1);
}

int	print_exit(t_token token)
{
	int	i;

	if (token.option[1] == NULL)
		exit(0);
	if (!is_all_num(token.option[1]))
		print_error();
	if (token.option[2] == NULL)
	{
		i = ft_atoi(token.option[1]);
		if (ft_strcmp(token.option[1], "0") == 0)
			exit(0);
		if (ft_strcmp(token.option[1], "-1") == 0)
			exit(-1);
		if (i == 0 || i == -1)
			print_error();
		printf("exit\n");
		exit(ft_atoi(token.option[1]) % 256);
	}
	printf("exit\nexit: too many arguments\n");
	g_status = 1;
	return (1);
}
