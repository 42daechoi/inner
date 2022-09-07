/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_heredoc2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:39:49 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/23 23:37:13 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	wait_heredoc(t_heredoc *hd)
{
	int	status;

	status = 0;
	waitpid(-1, &status, 0);
	if (WIFSIGNALED(status))
	{
		printf("\n");
		g_status = 1;
		hd->status = 1;
	}
}

void	unlink_lastdoc(t_token *token, t_heredoc hd, int token_cnt)
{
	hd.i = -1;
	while (++hd.i < token_cnt)
		if (token[hd.i].last_doc)
			unlink(token[hd.i].last_doc);
}

int	any_heredoc(t_token *token, int j, int i)
{
	while (token[j].str[i])
	{
		if (!is_quotes(token, token[j].str[i], j))
		{
			if (!ft_strncmp(&(token[j].str[i]), "<<", 2))
				return (1);
		}
		i++;
	}
	return (0);
}

int	any_infile(t_token *token, int j, int i)
{
	while (token[j].str[i])
	{
		if (!is_quotes(token, token[j].str[i], j))
		{
			if (token[j].str[i] == '<')
				return (1);
		}
		i++;
	}
	return (0);
}
