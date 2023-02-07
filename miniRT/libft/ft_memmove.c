/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:19:56 by kiyoon            #+#    #+#             */
/*   Updated: 2021/11/22 17:15:20 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*tmp;
	const char	*s;

	if (!dest && !src)
		return (dest);
	if (dest <= src)
	{
		tmp = dest;
		s = src;
		while (len--)
			*tmp++ = *s++;
	}
	else
	{
		tmp = dest;
		tmp += len;
		s = src;
		s += len;
		while (len--)
			*--tmp = *--s;
	}
	return (dest);
}
