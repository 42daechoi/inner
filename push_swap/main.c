/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:30:22 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/20 16:34:29 by daechoi          ###   ########.fr       */
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
	info->depth = 0;
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

void	init_ofs(t_var *var, t_stack *s)
{
	var->i = -1;
	var->cnt = 0;
	var->min = find_min_max(s, 0, 5);
	var->next_min = find_min_max(s, 2, 5);
}

void	only_fifth_sort(t_info *info)
{
	t_var	var;
	t_stack	*s;

	s = info->a;
	init_ofs(&var, s);
	while (++var.i < 5)
	{
		if (get_prev(s, 0)->data == var.min \
			|| get_prev(s, 0)->data == var.next_min)
		{
			pb(info);
			var.cnt++;
		}
		else
			ra(s);
		if (var.cnt == 2)
			break ;
	}
	if (info->b->data > info->b->next->data)
		sb(info->b);
	only_triple_sort(*info);
	pa(info);
	pa(info);
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
		else if (ac == 6)
			only_fifth_sort(&info);
		else
			q_sort_a(&info, info.a, ft_stacksize(info.a));
	}
}
