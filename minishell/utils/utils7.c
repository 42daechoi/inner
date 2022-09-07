/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:24:47 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/23 19:25:52 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_cwinfo(char const *s, char c, t_pipesplit *p)
{
	if (s[p->i] == '\'' && p->inquotes == 0)
		p->inquotes = 1;
	else if (s[p->i] == '\'' && p->inquotes == 1)
		p->inquotes = 0;
	if (s[p->i] == c && p->inquotes == 0)
		p->issep = 1;
	else
		p->issep = 0;
	if (s[p->i + 1] == c && p->issep == 1)
	{
		p->issep = 0;
		p->i++;
	}
}

void	get_cnt(char const *s, char c, t_pipesplit *p, size_t *pos)
{
	if (s[*pos] != c)
	{
		p->inword = 1;
		p->cnt++;
	}
	if (s[*pos] == c && s[(*pos) + 1] == c && p->inquotes == 0)
	{
		p->inword = 1;
		p->cnt += 2;
		(*pos)++;
	}
	if (s[*pos] == c && (p->inquotes == 1 || p->inquotes == 2))
		p->cnt++;
}

int	find_pipe(char *str, int *i, int *pos)
{
	if (str[*i] == '|')
	{
		if (*pos != -1)
			return (1);
		*pos = (*i)++;
		while (str[*i] && str[*i] != '|')
			(*i)++;
		while (++(*pos) < *i)
		{
			if (str[*pos] != ' ')
				return (0);
		}
	}
	return (-1);
}

void	get_inquotes(char c, t_pipesplit *p)
{
	if (c == '\'' && p->inquotes == 0)
		p->inquotes = 1;
	else if (c == '\"' && p->inquotes == 0)
		p->inquotes = 2;
	else if (c == '\'' && p->inquotes == 1)
		p->inquotes = 0;
	else if (c == '\"' && p->inquotes == 2)
		p->inquotes = 0;
}
