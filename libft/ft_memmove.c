/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:26:06 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/16 20:44:54 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dest, const void *src, size_t cnt)
{
	char		*temp;
	const char	*s;

	temp = dest;
	s = src;
	if (dest <= src)
	{
		while (cnt > 0)
		{
			*tmp++ = *s++;
			cnt--;
		}
	}
	else
	{
		temp += cnt;
		s += cnt;
		while (cnt > 0)
		{
			*--tmp = *--s;
			cnt--;
		}
	}
	return (dest);
}
