/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:30:25 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/23 14:21:49 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (little[j] == big[i + j])
		{
			while (little[j] && big[i + j])
			{
				if (little[j] != big[i + j] || i + j >= len)
					break ;
				j++;
			}
			if (!little[j])
				return (&((char *)big)[i]);
		}
		i++;
	}
	return (NULL);
}
