/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:30:22 by daechoi           #+#    #+#             */
/*   Updated: 2022/06/29 17:55:15 by daechoi          ###   ########.fr       */
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
	info->cal_cnt = 0;
	info->init_ssize = ft_stacksize(info->a);
	info->pivot = ft_stacklast(info->a)->data;
}



int main(int ac, char **av)
{
	t_info	info;
	int		temp;

	if (ac < 2)
		exit(1);
	init_info(&info, ac, av);
	int i = 0;
	sort(&info);
	printf("bottom\n");
	while (info.a != NULL)
	{
		printf("a : %d\n", info.a->data);
		info.a = info.a->next;
	}
	printf("top\n");
	while (info.b != NULL)
	{
		printf("b : %d\n", info.b->data);
		info.b = info.b->next;
	}
}