/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:30:22 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/18 20:04:29 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_info(t_info *info, int ac, char **av)
{
	int	temp;

	temp = ft_atoi(av[--ac]);
	info->a = ft_newstack(temp);
	while (ac > 1)
	{
		temp = ft_atoi(av[--ac]);
		ft_push(&info->a, ft_newstack(temp));
	}
	info->b = NULL;
}

int err_check(char **av)
{
	int i;
	int j;
	int	k;
	int	temp;

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
		temp = ft_atoi(av[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (0);
		k = i + 1;
		while (av[k])
		{
			if (av[i] == av[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

void	only_triple_sort(t_info info)
{
	t_stack	*a;

	a = info.a;
	while (!(a->data > a->next->data && a->data > a->next->next->data))
		ra(a);
	if (a->next->data < a->next->next->data)
		sa(a);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac < 2)
		exit(1);
	if (!err_check(av))
		ft_printerr("Error\n");
	init_info(&info, ac, av);
	if (!is_sorted(info.a, ft_stacksize(info.a), 0))
	{
		if (ac == 4)
			only_triple_sort(info);
		else
			q_sort_a(&info, info.a, ft_stacksize(info.a));
	}
	while (info.a != NULL)
	{
		printf("a : %d", info.a->data);
		info.a = info.a->next;
	}
}
