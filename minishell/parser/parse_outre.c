/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_outre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:06:03 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/18 22:32:11 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	do_append(t_token *token, t_lenpos *l, int *k)
{	
	l->i++;
	while (token[l->j].str[++l->i] == ' ')
		;
	l->pos = l->i;
	while (token[l->j].str[l->i] != ' ' && token[l->j].str[l->i] \
		&& token[l->j].str[l->i] != '<' && token[l->j].str[l->i] != '>')
	{
		l->len++;
		l->i++;
	}
	token[l->j].append_flag[*k] = 1;
	token[l->j].outfile[(*k)++] \
		= ft_substr(token[l->j].str, l->pos, l->len);
	l->i--;
}

void	do_outfile(t_token *token, t_lenpos *l, int *k)
{
	while (token[l->j].str[++l->i] == ' ')
		;
	l->pos = l->i;
	while (token[l->j].str[l->i] != ' ' && token[l->j].str[l->i] \
		&& token[l->j].str[l->i] != '<' && token[l->j].str[l->i] != '>')
	{
		l->len++;
		l->i++;
	}
	token[l->j].append_flag[*k] = 0;
	token[l->j].outfile[(*k)++] \
		= ft_substr(token[l->j].str, l->pos, l->len);
	l->i--;
}

int	malloc_outre(t_token *token, t_lenpos *lp)
{
	if (token[lp->j].outre_cnt + token[lp->j].append_cnt <= 0)
		return (0);
	token[lp->j].outfile = (char **)ft_malloc(sizeof(char *) \
		* (token[lp->j].outre_cnt + token[lp->j].append_cnt + 1));
	token[lp->j].outfile[token[lp->j].outre_cnt \
				+ token[lp->j].append_cnt] = NULL;
	token[lp->j].append_flag = ft_malloc(sizeof(int) \
		* (token[lp->j].outre_cnt + token[lp->j].append_cnt + 1));
	return (1);
}

void	parse_outre(t_token *token, int token_cnt)
{
	t_lenpos	lp;
	int			k;

	lp.j = -1;
	while (++lp.j < token_cnt)
	{
		k = 0;
		lp.i = -1;
		token[lp.j].in_quotes = 0;
		if (!malloc_outre(token, &lp))
			continue ;
		while (token[lp.j].str[++lp.i])
		{
			lp.len = 0;
			lp.pos = 0;
			if (!is_quotes(token, token[lp.j].str[lp.i], lp.j))
			{
				if (!ft_strncmp(&(token[lp.j].str[lp.i]), ">>", 2))
					do_append(token, &lp, &k);
				else if (token[lp.j].str[lp.i] == '>')
					do_outfile(token, &lp, &k);
			}
		}
	}
}
