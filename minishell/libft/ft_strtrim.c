/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:45:28 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/17 17:56:25 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start_index(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	end_index(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return ((int)(len - i));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = start_index(s1, set);
	end = end_index(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	new = (char *)ft_malloc(sizeof(char) * (end - start + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1 + start, end - start + 1);
	return (new);
}
