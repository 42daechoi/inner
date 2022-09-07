/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubleq_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:57:59 by daechoi           #+#    #+#             */
/*   Updated: 2022/08/23 17:31:34 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	ft_countword2(char const *s, char c)
{
	t_pipesplit	p;

	init_pipesplit(&p);
	while (s[++p.i])
	{
		get_cwinfo(s, c, &p);
		if (p.inword == 1 && p.issep == 1)
			p.inword = 0;
		if ((p.inword == 0 && p.issep == 0))
		{
			p.inword = 1;
			p.cnt++;
		}
	}
	return (p.cnt);
}

size_t	ft_countspell2(char const *s, char c, size_t *pos)
{
	t_pipesplit	p;

	init_pipesplit(&p);
	while (s[*pos])
	{
		if (s[*pos] == '\'' && p.inquotes == 0)
			p.inquotes = 1;
		else if (s[*pos] == '\'' && p.inquotes == 1)
			p.inquotes = 0;
		if (p.inword == 1 && \
			(s[*pos] == c && s[(*pos) + 1] != c) && p.inquotes == 0)
			break ;
		get_cnt(s, c, &p, pos);
		(*pos)++;
	}
	return (p.cnt);
}

int	ft_checkleaks2(char **arr, int i)
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

char	**ft_errorhandler2(void)
{
	char	**arr;

	arr = (char **)ft_malloc(sizeof(char *));
	if (!arr)
		return (NULL);
	arr[0] = NULL;
	return (arr);
}

char	**doubleq_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	pos;
	size_t	spellcnt;
	size_t	j;

	i = -1;
	pos = 0;
	if (!s || *s == '\0')
		return (ft_errorhandler2());
	arr = (char **)ft_calloc((ft_countword2(s, c) + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	while (++i < ft_countword2(s, c))
	{
		spellcnt = ft_countspell2(s, c, &pos);
		arr[i] = (char *)ft_calloc((spellcnt + 1), sizeof(char));
		if (ft_checkleaks2(arr, i) == 0)
			return (NULL);
		j = 1;
		while (spellcnt > 0)
			arr[i][(spellcnt--) - 1] = s[pos - (j++)];
	}
	return (arr);
}
