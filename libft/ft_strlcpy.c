/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:44:29 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/16 20:43:19 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen(src);
	while (i < size - 1 && src[i] && size != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (str_len);
}
