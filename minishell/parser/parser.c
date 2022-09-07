/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:08:54 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/20 17:42:27 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_quotes(t_token *token, char c, int i)
{
	if (c == '\'' && token[i].in_quotes == 0)
		token[i].in_quotes = 1;
	else if (c == '\"' && token[i].in_quotes == 0)
		token[i].in_quotes = 2;
	else if (c == '\'' && token[i].in_quotes == 1)
		token[i].in_quotes = 0;
	else if (c == '\"' && token[i].in_quotes == 2)
		token[i].in_quotes = 0;
	return (token[i].in_quotes);
}

void	match_redirect(t_token *token, int *j, int *i)
{
	if (!is_quotes(token, token[*j].str[*i], *j))
	{
		if (!ft_strncmp(&(token[*j].str[*i]), "<<", 2))
		{
			token[*j].heredoc_cnt++;
			(*i)++;
		}
		else if (!ft_strncmp(&(token[*j].str[*i]), ">>", 2))
		{
			token[*j].append_cnt++;
			(*i)++;
		}
		else if (token[*j].str[*i] == '<')
			token[*j].inre_cnt++;
		else if (token[*j].str[*i] == '>')
			token[*j].outre_cnt++;
	}
}

void	set_direct_cnt(t_token *token, int token_cnt)
{
	int	i;
	int	j;

	j = 0;
	while (j < token_cnt)
	{
		token[j].in_quotes = 0;
		i = 0;
		token[j].inre_cnt = 0;
		token[j].outre_cnt = 0;
		token[j].heredoc_cnt = 0;
		token[j].append_cnt = 0;
		while (token[j].str[i])
		{
			match_redirect(token, &j, &i);
			i++;
		}
		j++;
	}
}

int	parse_token(t_token *token, int token_cnt, char **envp, char *str)
{
	int	hd_status;

	set_direct_cnt(token, token_cnt);
	parse_inre(token, token_cnt);
	parse_outre(token, token_cnt);
	hd_status = parse_heredoc(token, token_cnt);
	parse_cmd(token, token_cnt, envp);
	if (hd_status)
		free_all_token(token, token_cnt, str);
	return (hd_status);
}
