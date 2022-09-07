/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:25:36 by kiyoon            #+#    #+#             */
/*   Updated: 2022/08/17 17:53:58 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*pb;
	size_t			allocate;

	ptr = (void *)ft_malloc(count * size);
	if (!ptr)
		return (NULL);
	pb = ptr;
	allocate = count * size;
	while (allocate-- > 0)
		*pb++ = 0;
	return (ptr);
}
