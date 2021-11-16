/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:24:28 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/16 20:45:32 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	const char	*temp = NULL;

	while (*s)
	{
		if (*s == (char)c)
			temp = s;
		s++;
	}
	return ((char *)temp);
}
