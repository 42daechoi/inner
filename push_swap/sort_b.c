/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:20:49 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/19 21:28:03 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_dib(t_var *v)
{
	v->ra_cnt = 0;
	v->rb_cnt = 0;
	v->pa_cnt = 0;
}

void	divide_bnum(t_var *v, t_info *info)
{
	if (v->i < info->pivot_s)
	{
		rb(info->b);
		v->rb_cnt++;
	}
	else
	{
		pa(info);
		v->pa_cnt++;
		if (v->i < info->pivot_b)
		{
			ra(info->a);
			v->ra_cnt++;
		}
	}
}

void	do_instruct_b(t_info *info, int s_size)
{
	t_var	v;

	init_dib(&v);
	get_pivot(info, info->b, s_size);
	while (s_size > 0)
	{
		v.i = ft_stacklast(info->b)->data;
		divide_bnum(&v, info);
		s_size--;
	}
	q_sort_a(info, info->a, v.pa_cnt - v.ra_cnt);
	reverse_in_sort(info, v.ra_cnt, v.rb_cnt);
	q_sort_a(info, info->a, v.ra_cnt);
	q_sort_b(info, info->b, v.rb_cnt);
}

void	push_iter(t_info *info, int s_size)
{
	while (s_size > 0)
	{
		pa(info);
		s_size--;
	}
}

void	q_sort_b(t_info *info, t_stack *s, int s_size)
{
	if (is_sorted(info->b, s_size, 1))
	{
		push_iter(info, s_size);
		return ;
	}
	if (s_size == 1)
	{
		pa(info);
		return ;
	}
	else if (s_size == 2)
	{
		double_sort(info, s, 1);
		return ;
	}
	else if (s_size == 3)
	{
		triple_sort(info, s, 1);
		return ;
	}
	do_instruct_b(info, s_size);
}
