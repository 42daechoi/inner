/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:05:33 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/18 22:32:02 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	find_inre(t_token *token, t_lenpos *lp, int *k)
{
	lp->len = 0;
	lp->pos = 0;
	if (!is_quotes(token, token[lp->j].str[lp->i], lp->j))
	{
		if (!ft_strncmp(&(token[lp->j].str[lp->i]), "<<", 2))
			lp->i += 2;
		if (token[lp->j].str[lp->i] == '<')
		{
			while (token[lp->j].str[++lp->i] == ' ')
				;
			lp->pos = lp->i;
			while (token[lp->j].str[lp->i] != ' ' \
				&& token[lp->j].str[lp->i] && token[lp->j].str[lp->i] != '<' \
				&& token[lp->j].str[lp->i] != '>')
			{
				lp->len++;
				lp->i++;
			}
			token[lp->j].infile[(*k)++] \
				= ft_substr(token[lp->j].str, lp->pos, lp->len);
			lp->i--;
		}
	}
}

void	parse_inre(t_token *token, int token_cnt)
{
	t_lenpos	lp;
	int			k;

	lp.j = -1;
	while (++lp.j < token_cnt)
	{
		k = 0;
		lp.i = -1;
		if (token[lp.j].inre_cnt <= 0)
			continue ;
		token[lp.j].infile = \
			(char **)ft_malloc(sizeof(char *) * (token[lp.j].inre_cnt + 1));
		token[lp.j].infile[token[lp.j].inre_cnt] = NULL;
		while (token[lp.j].str[++lp.i])
			find_inre(token, &lp, &k);
		lp.j++;
	}
}
