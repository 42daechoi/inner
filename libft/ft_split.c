/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:23:11 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/17 20:17:10 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countword(char const *s, char c)
{
	int		inword;
	int		issep;
	size_t	i;
	size_t	cnt;

	inword = 0;
	issep = 0;
	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			issep = 1;
		else
			issep = 0;
		if (inword == 1 && issep == 1)
		{
			inword = 0;
		}
		if (inword == 0 && issep == 0)
		{
			inword = 1;
			cnt++;
		}
		i++;
	}
	return (cnt);
}

size_t	ft_countspell(char const *s, char c, size_t *pos)
{
	size_t	i;
	size_t	cnt;
	int		inword;

	i = *pos;
	inword = 0;
	while (s[i])
	{
		if (inword == 1 && s[i] == c)
			break ;
		if (s[i] != c)
		{
			inword == 1;
			cnt++;
		}
		i++;
	}
	*pos += cnt;
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	wordcnt;
	size_t	i;
	size_t	j;
	size_t	pos;

	i = 0;
	pos = 0;
	wordcnt = ft_countword(s, c);
	arr = (char **)malloc(wordcnt * sizeof(char *));
	if (!arr)
		return (NULL);
	while (i < wordcnt)
	{
		arr[i] = (char *)malloc(ft_countspell(s, c, &pos) * sizeof(char));
		j = 0;
		while (j < countspell(s, c, &pos))
		{
			arr[i][j] = s[pos++];
	}
	return (NULL);
}

int main()
{
	char *s = "s0saf0fdsa0fdsg0gfh00h0h0d000gg0g0g0g0sd0";
	char c = '0';

	printf("%zu", ft_countword(s, c));
}
