/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:09:26 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/23 23:11:23 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_double(t_token *token, int index)
{
	free_infile(token, index);
	free_outfile(token, index);
	free_arr(token, index);
	free_option(token, index);
	free_here_doc(token, index);
}

void	free_single(t_token *token, int i)
{
	if (token[i].str)
	{
		free(token[i].str);
		token[i].str = NULL;
	}
	if (token[i].cmd)
	{
		free(token[i].cmd);
		token[i].cmd = NULL;
	}
	if (token[i].last_doc)
	{
		free(token[i].last_doc);
		token[i].last_doc = NULL;
	}
	if (token[i].append_flag)
	{
		free(token[i].append_flag);
		token[i].append_flag = NULL;
	}
}

void	free_all_token(t_token *token, int len, char *str)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free_single(token, i);
		free_double(token, i);
		i++;
	}
	free(token);
	free(str);
	token = NULL;
	str = NULL;
}
