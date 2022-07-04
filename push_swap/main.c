/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:30:22 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/04 20:29:52 by daechoi          ###   ########.fr       */
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
	info->ra_cnt = 0;
	info->rb_cnt = 0;
	info->pa_cnt = 0;
	info->pb_cnt = 0;
}

void	init_cnt(t_info *info)
{
	info->ra_cnt = 0;
	info->rb_cnt = 0;
	info->pa_cnt = 0;
	info->pb_cnt = 0;
}

void	print_all(t_info *info, int s_size)
{
	t_stack *s1 = info->a;
	t_stack *s2 = info->b;
	while (s1 != NULL)
	{
		printf("a : %d\n", s1->data);
		s1 = s1->next;
	}
	while (s2 != NULL)
	{
		printf("b : %d\n", s2->data);
		s2 = s2->next;
	}
	printf("p_s : %d\np_b : %d\n", info->pivot_s, info->pivot_b);
	printf("ra : %d\nrb : %d\npa : %d\npb : %d\nssize : %d\n", info->ra_cnt, info->rb_cnt, info->pa_cnt, info->pb_cnt, s_size);
	printf("---------------------------\n");
}

int main(int ac, char **av)
{
	t_info	info;
	int		temp;

	if (ac < 2)
		exit(1);
	init_info(&info, ac, av);
	int i = 0;
	a_to_b(&info, ft_stacksize(info.a));
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