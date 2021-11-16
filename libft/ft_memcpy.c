/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:05:57 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/16 20:42:43 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char		*temp;
	const char	*s;

	temp = dest;
	s = src;
	while (size > 0)
	{
		*temp++ = *s++;
		size--;
	}
	return (dest);
}
