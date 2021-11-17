/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:17:23 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/17 19:00:19 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countstr(char const *s1, char const *set, size_t s1_len)
{
	size_t	i;
	size_t	str_len;

	i = 0;
	str_len = 0;
	while (i < s1_len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			str_len++;
		i++;
	}
	return (str_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	str_len;
	size_t	s1_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	str_len = ft_countstr(s1, set, s1_len);
	str = (char *)malloc(str_len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (i < s1_len)
	{
		if (ft_strchr(set, s1[i]) == 0)
		{
			str[j++] = s1[i];
		}
		i++;
	}
	return (str);
}
