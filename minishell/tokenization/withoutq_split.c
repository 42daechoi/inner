/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   withoutq_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:57:59 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/23 17:18:40 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	ft_countword(char const *s, char c)
{
	t_pipesplit	p;

	init_pipesplit(&p);
	while (s[++p.i])
	{
		get_inquotes(s[p.i], &p);
		if (s[p.i] == c && p.inquotes == 0)
			p.issep = 1;
		else
			p.issep = 0;
		if (p.inword == 1 && p.issep == 1)
			p.inword = 0;
		if (p.inword == 0 && p.issep == 0)
		{
			p.inword = 1;
			p.cnt++;
		}
	}
	return (p.cnt);
}

size_t	ft_countspell(char const *s, char c, size_t *pos)
{
	t_pipesplit	p;

	init_pipesplit(&p);
	while (s[*pos])
	{
		get_inquotes(s[*pos], &p);
		if (p.inword == 1 && s[*pos] == c && p.inquotes == 0)
			break ;
		if (s[*pos] != c)
		{
			p.inword = 1;
			p.cnt++;
		}
		if (s[*pos] == c && (p.inquotes == 1 || p.inquotes == 2))
			p.cnt++;
		(*pos)++;
	}
	return (p.cnt);
}

int	ft_checkleaks(char **arr, int i)
{
	if (!arr[i])
	{
		while (--i >= 0)
			free(arr[i]);
		free(arr);
		return (0);
	}
	return (1);
}

char	**ft_errorhandler(void)
{
	char	**arr;

	arr = (char **)ft_malloc(sizeof(char *));
	if (!arr)
		return (NULL);
	arr[0] = NULL;
	return (arr);
}

char	**withoutq_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	pos;
	size_t	spellcnt;
	size_t	j;

	i = -1;
	pos = 0;
	if (!s || *s == '\0')
		return (ft_errorhandler());
	arr = (char **)ft_calloc((ft_countword(s, c) + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	while (++i < ft_countword(s, c))
	{
		spellcnt = ft_countspell(s, c, &pos);
		arr[i] = (char *)ft_calloc((spellcnt + 1), sizeof(char));
		if (ft_checkleaks(arr, i) == 0)
			return (NULL);
		j = 1;
		while (spellcnt > 0)
			arr[i][(spellcnt--) - 1] = s[pos - (j++)];
	}
	return (arr);
}
