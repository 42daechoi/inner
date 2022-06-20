/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:57:31 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/16 20:42:03 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t cnt, size_t size)
{
	void	*arr;

	arr = (void *)malloc(cnt * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, cnt * size);
	return (arr);
}	
