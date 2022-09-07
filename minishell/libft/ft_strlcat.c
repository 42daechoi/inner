/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:55:31 by kiyoon            #+#    #+#             */
/*   Updated: 2021/11/24 14:56:10 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	j = dest_len;
	if (dest_len < size - 1 && size > 0)
	{
		while (src[i] && dest_len + i < size - 1)
		{
			dest[j] = src[i];
			j++;
			i++;
		}
		dest[j] = 0;
	}
	if (dest_len >= size)
		dest_len = size;
	return (dest_len + src_len);
}
