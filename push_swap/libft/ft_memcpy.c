/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:05:57 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/26 16:06:17 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char		*temp;
	const char	*s;

	if (!dest && !src)
		return (0);
	temp = dest;
	s = src;
	while (size > 0)
	{
		*temp++ = *s++;
		size--;
	}
	return (dest);
}
