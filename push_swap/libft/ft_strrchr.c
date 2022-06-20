/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:24:28 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/22 20:20:44 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp = NULL;
	int			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			temp = &s[i];
		i++;
	}
	if (s[i] == (char)c)
		temp = &s[i];
	return ((char *)temp);
}
