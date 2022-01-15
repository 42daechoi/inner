/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_nbr_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:53:37 by daechoi           #+#    #+#             */
/*   Updated: 2022/01/16 05:21:33 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_malloc_nbr_base(unsigned long nbr, char *base)
{
	unsigned long	base_len;
	char			*arr;
	unsigned long	temp;
	int				i;

	i = 0;
	base_len = (unsigned long)ft_strlen(base);
	temp = nbr;
	if (!temp)
		return (ft_strdup("0"));
	while (temp)
	{
		temp = temp / base_len;
		i++;
	}
	arr = (char *)malloc((i + 1) * sizeof(char));
	arr[i] = '\0';
	while (--i >= 0)
	{
		arr[i] = base[nbr % base_len];
		nbr = nbr / base_len;
	}
	return (arr);
}
