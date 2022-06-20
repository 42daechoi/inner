/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:26:06 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/24 18:29:11 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t cnt)
{
	char		*temp;
	const char	*s;

	temp = dest;
	s = src;
	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		while (cnt-- > 0)
			*temp++ = *s++;
	}
	else
	{
		temp += cnt;
		s += cnt;
		while (cnt-- > 0)
			*--temp = *--s;
	}
	return (dest);
}
