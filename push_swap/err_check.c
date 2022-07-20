/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:49:55 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/20 21:03:34 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_samenum(char **av, int i)
{
	int	k;

	k = i + 1;
	while (av[k])
	{
		if (ft_atoi(av[i]) == ft_atoi(av[k]))
			return (0);
		k++;
	}
	return (1);
}

int	err_check(char **av)
{
	int			i;
	int			j;
	long long	temp;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
				j++;
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		temp = ft_atol(av[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (0);
		if (!check_samenum(av, i))
			return (0);
		i++;
	}
	return (1);
}
