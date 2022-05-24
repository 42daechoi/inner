/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:10:47 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/22 16:43:59 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_temp;
	unsigned char	*src_temp;

	i = 0;
	dest_temp = (unsigned char *)dest;
	src_temp = (unsigned char *)src;
	while (i < n)
	{
		if (dest_temp[i] != src_temp[i])
			return (dest_temp[i] - src_temp[i]);
		i++;
	}
	return (0);
}
