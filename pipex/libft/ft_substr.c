/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:38:25 by daechoi           #+#    #+#             */
/*   Updated: 2022/06/07 15:23:29 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	str_len;

	i = 0;
	if (!s || start < 0)
		return (NULL);
	str_len = ft_strlen(s);
	if ((size_t)start >= str_len)
		return (ft_strdup(""));
	if (len > str_len)
		str = (char *)malloc((str_len - start + 1) * sizeof(char));
	else
		str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
