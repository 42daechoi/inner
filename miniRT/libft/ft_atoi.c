/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 01:21:13 by kiyoon            #+#    #+#             */
/*   Updated: 2021/11/22 19:21:58 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	i;
	long long	min;
	long long	ans;

	ans = 0;
	min = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			min = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans *= 10;
		ans += str[i++] - '0';
		if (ans * min > 2147483647)
			return (-1);
		if (ans * min < -2147483648)
			return (0);
	}
	ans *= min;
	return ((int)ans);
}
