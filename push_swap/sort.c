/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:25:03 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/04 20:59:29 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack, char c)
{
	if (ft_stacksize(stack) < 2)
		return (false);
	while (stack->next != NULL)
	{
		if (c == 'a')
		{
			if (stack->data < stack->next->data)
				return (false);
		}
		else if (c == 'b')
		{
			if (stack->data > stack->next->data)
				return (false);
		}
		else
			ft_printerr("sort arg error");
		stack = stack->next;
		
	}
	return (true);
}

void	double_sort(t_stack *a)
{
	if (a->data < a->next->data)
		sa(a);
}

void	triple_sort(t_stack *a)
{
	while (a->data < a->next->data || a->data < a->next->next->data)
		ra(a);
	if (a->next->data < a->next->next->data)
		sa(a);
}

void	a_to_b(t_info *info, int s_size)
{
	t_stack	*top;
	int     ra_cnt;
	int     rb_cnt;
	int     pb_cnt;

	if (hard_sort(info, info->a))
		return ;
	get_pivot(info, info->a);
	init_cnt(info);
	while (s_size > 0)
	{
		top = ft_stacklast(info->a);
		if (top->data < info->pivot_b)
		{
			pb(info);
			info->pb_cnt++;
			if (top->data >= info->pivot_s)
			{
				rb(info->b);
				info->rb_cnt++;
			}
		}
		else
		{
			ra(info->a);
			info->ra_cnt++;
		}
		s_size--;
	}
	ra_cnt = info->ra_cnt;
	rb_cnt = info->rb_cnt;
	while (ra_cnt-- > 0 && rb_cnt-- > 0)
		rrr(info->a, info->b);
	while (ra_cnt-- > 0)
		rra(info->a);
	while (rb_cnt-- > 0)
		rrb(info->b);
	ra_cnt = info->ra_cnt;
	rb_cnt = info->rb_cnt;
	pb_cnt = info->pb_cnt;
	a_to_b(info, ra_cnt);
	b_to_a(info, rb_cnt);
	b_to_a(info, info->pb_cnt - rb_cnt);
}

void	b_to_a(t_info *info, int s_size)
{
	t_stack	*top;
	int     ra_cnt;
	int     rb_cnt;
	int     pa_cnt;
	
	if (hard_sort(info, info->b))
		return ;
	get_pivot(info, info->b);
	init_cnt(info);
	while (s_size > 0)
	{
		top = ft_stacklast(info->b);
		if (top->data < info->pivot_s)
		{
			rb(info->b);
			info->rb_cnt++;
		}
		else
		{
			pa(info);
			info->pa_cnt++;
			if (top->data < info->pivot_b)
			{
				ra(info->b);
				info->ra_cnt++;
			}
		}
		s_size--;
	}
	print_all(info, s_size);
	sleep(2);
	ra_cnt = info->ra_cnt;
	rb_cnt = info->rb_cnt;
	pa_cnt = info->pa_cnt;
	a_to_b(info, pa_cnt - ra_cnt);
	while (ra_cnt-- > 0 && rb_cnt-- != 0)
		rrr(info->a, info->b);
	while (ra_cnt-- > 0)
		rra(info->a);
	while (rb_cnt-- > 0)
		rrb(info->b);
	ra_cnt = info->ra_cnt;
	rb_cnt = info->rb_cnt;
	a_to_b(info, ra_cnt);
	b_to_a(info, rb_cnt);
}

int	hard_sort(t_info *info, t_stack *s)
{
	if (ft_stacksize(s) == 2)
		double_sort(s);
    else if (ft_stacksize(s) == 3)
		triple_sort(s);
    else
		return (0);
	return (1);
}