/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:33:23 by daechoi           #+#    #+#             */
/*   Updated: 2021/11/19 20:24:02 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_setstr(unsigned int num, unsigned int digit, int cnt)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(cnt * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (i < cnt)
	{
		str[i] = num / digit + '0';
		num -= num / digit * digit;
		digit /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	digit;
	unsigned int	num;
	int				cnt;
	char			*str;

	digit = 1;
	cnt = 0;
	if (n < -2147483648 || n > 2147483647)
		return (NULL);
	if (n < 0)
		num = (unsigned int)(-n);
	else
		num = (unsigned int)n;
	while (1)
	{
		if (num / digit > 0)
			cnt++;
		else
			break ;
		digit *= 10;
	}
	digit /= 10;
	str = ft_setstr(num, digit, cnt);
	return (str);
}
