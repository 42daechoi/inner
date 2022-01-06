/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_nbr_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:53:37 by daechoi           #+#    #+#             */
/*   Updated: 2022/01/06 18:11:07 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_malloc_nbr_base(long long nbr, char *base)
{
	long long	base_len;
	char		*arr;
    long long	temp;
	int			i;

	i = 0;
	base_len = (long long)ft_strlen(base);
    temp = nbr;
	if (nbr >= 0)
	{
        while (temp)
        {
            temp = temp / base_len;
            i++;
        }
        arr = (char *)malloc((i + 1) * sizeof(char));
		arr[i] = '\0';
		while (--i >= 0)
		{
			if (ft_isdigit((int)(nbr % base_len) +'0'))
				arr[i] = nbr % base_len + '0';
			else
				arr[i] = nbr % base_len + 87;
			nbr = nbr / base_len;
		}
	}
    else
        arr = ft_strdup("");
    return (arr);
}