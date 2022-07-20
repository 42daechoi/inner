/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:25:03 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/20 16:35:35 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_dia(t_var *v)
{
	v->ra_cnt = 0;
	v->rb_cnt = 0;
	v->pb_cnt = 0;
}

void	divide_anum(t_var *v, t_info *info)
{
	if (v->i > info->pivot_b)
	{
		ra(info->a);
		v->ra_cnt++;
	}
	else
	{
		pb(info);
		v->pb_cnt++;
		if (v->i >= info->pivot_s)
		{
			rb(info->b);
			v->rb_cnt++;
		}
	}
}

void	zerodepth_anum(t_var *v, t_info *info)
{
	if (v->i >= info->pivot_b)
	{
		ra(info->a);
		v->ra_cnt++;
	}
	else
	{
		pb(info);
		v->pb_cnt++;
		if (v->i < info->pivot_s)
		{
			rb(info->b);
			v->rb_cnt++;
		}
	}
}

void	do_instruct_a(t_info *info, int s_size)
{
	t_var	v;

	init_dia(&v);
	get_pivot(info, info->a, s_size);
	while (s_size > 0)
	{
		v.i = ft_stacklast(info->a)->data;
		if (info->depth != 0)
			divide_anum(&v, info);
		else
			zerodepth_anum(&v, info);
		s_size--;
	}
	if (info->depth != 0)
		reverse_in_sort(info, v.ra_cnt, v.rb_cnt);
	info->depth++;
	q_sort_a(info, info->a, v.ra_cnt);
	q_sort_b(info, info->b, v.rb_cnt);
	q_sort_b(info, info->b, v.pb_cnt - v.rb_cnt);
}

void	q_sort_a(t_info *info, t_stack *s, int s_size)
{
	if (is_sorted(info->a, s_size, 0))
		return ;
	if (s_size == 2)
	{
		double_sort(info, s, 0);
		return ;
	}
	else if (s_size == 3)
	{
		triple_sort(info, s, 0);
		return ;
	}
	do_instruct_a(info, s_size);
}
