/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:15:30 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/24 19:12:44 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s || !set)
		return (NULL);
	if (*s == '\0')
		return (ft_strdup(""));
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] && ft_strchr(set, s[i]))
		i++;
	while (s[j] && j > 0 && ft_strchr(set, s[j]))
		j--;
	if (i > j)
		return (ft_strdup(""));
	str = (char *)malloc((j - i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[i], j - i + 2);
	return (str);
}
