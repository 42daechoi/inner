/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:22:30 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/18 17:39:35 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	echo_withn(t_token token, int *i)
{
	if (token.option[2] == NULL)
		return (1);
	else
	{
		*i = 2;
		while (token.option[(*i) + 1])
			printf("%s ", token.option[(*i)++]);
		printf("%s", token.option[*i]);
		return (1);
	}
	return (0);
}

int	is_option(t_token token)
{
	int	i;

	i = 1;
	if (ft_strncmp(token.option[1], "-", 1) != 0)
		return (1);
	while (token.option[1][i] != '\0')
	{
		if (token.option[1][i++] != 'n')
			return (1);
	}
	return (0);
}

int	print_echo(t_token token)
{
	int	i;

	g_status = 0;
	if (token.option[1] == NULL)
		return (printf("\n"));
	else if (!is_option(token))
	{
		if (echo_withn(token, &i) == 1)
			return (1);
	}
	else
	{
		i = 1;
		while (token.option[i + 1])
			printf("%s ", token.option[i++]);
		printf("%s", token.option[i]);
		printf("\n");
		return (1);
	}
	return (0);
}
