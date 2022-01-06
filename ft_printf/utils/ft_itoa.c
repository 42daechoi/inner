/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:33:23 by daechoi           #+#    #+#             */
/*   Updated: 2022/01/06 18:10:59 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_zerostr(void)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_strmalloc(int sign, int *i, int *cnt)
{
	char	*str;

	if (sign < 0)
	{
		str = (char *)malloc(*cnt * sizeof(char) + 2);
		if (!str)
			return (NULL);
		str[0] = '-';
		(*i)++;
		(*cnt)++;
	}
	else
	{
		str = (char *)malloc(*cnt * sizeof(char) + 1);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*ft_setstr(long long num, long long digit, int cnt, int sign)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strmalloc(sign, &i, &cnt);
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

void	ft_setparam(long long *num, long long *digit, int *cnt)
{
	while (1)
	{
		if ((long long)*num / *digit > 0)
			(*cnt)++;
		else
			break ;
		(*digit) *= 10;
	}
	(*digit) /= 10;
}

char	*ft_itoa(int n)
{
	long long	digit;
	long long	num;
	int			cnt;
	char		*str;
	int			sign;

	digit = 1;
	cnt = 0;
	sign = 1;
	if (n < -2147483648 || n > 2147483647)
		return (NULL);
	if (n == 0)
		return (ft_zerostr());
	else if (n < 0)
	{
		sign = -1;
		num = (long long)n * -1;
	}
	else
		num = (long long)n;
	ft_setparam(&num, &digit, &cnt);
	str = ft_setstr(num, digit, cnt, sign);
	if (!str)
		return (NULL);
	return (str);
}
