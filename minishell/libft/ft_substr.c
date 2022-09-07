/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:24:00 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/17 17:56:31 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*temp;

	if (!s || start < 0 || len < 0)
		return (NULL);
	i = 0;
	temp = (char *)ft_malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	while (start < ft_strlen(s) && i < len)
	{
		temp[i] = s[start];
		i++;
		start++;
	}
	temp[i] = '\0';
	return (temp);
}
