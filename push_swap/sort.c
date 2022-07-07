/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:25:03 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/07 20:52:55 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack, int flag)
{
	if (ft_stacksize(stack) < 2)
		return (false);
	if (flag == 0)
	{
		while (stack->next != NULL)
		{
			if (stack->data < stack->next->data)
				return (false);
			stack = stack->next;
		}
	}
	else
	{
		while (stack->next != NULL)
		{
			if (stack->data > stack->next->data)
				return (false);
			stack = stack->next;
		}
	}
	return (true);
}

void	double_sort(t_info *info, t_stack *s, int flag)
{
	if (!is_sorted(s, flag) && flag == 0)
		sa(s);
	if (is_sorted(s, flag) && flag == 1)
	{
		pa(info);
		pa(info);
	}
}

void	triple_sort(t_info *info, t_stack *s, int flag)
{
	if (flag == 0)
	{
		while (s->data < s->next->data || s->data < s->next->next->data)
			ra(info->a);
		if (s->next->data < s->next->next->data)
			sa(info->a);
	}
	else
	{
		while (s->data > s->next->data || s->data > s->next->next->data)
			rb(info->b);
		if (s->next->data > s->next->next->data)
			sb(info->b);
		pa(info);
		pa(info);
		pa(info);
	}
}

void	a_to_b(t_info *info, int s_size)
{
	int		top_data;
	int     ra_cnt;
	int     rb_cnt;
	int     pb_cnt;
	int		i;
	int		j;

	if (hard_sort(info, info->a, 0) || s_size <= 0 || is_sorted(info->a, 0))
		return ;
	get_pivot(info, info->a);
	init_cnt(info);
	ra_cnt = 0;
	rb_cnt = 0;
	pb_cnt = 0;
	i = 0;
	j = 0;
	while (s_size > 0)
	{
		top_data = ft_stacklast(info->a)->data;
		if (top_data < info->pivot_b)
		{
			pb(info);
			pb_cnt++;
			if (top_data >= info->pivot_s)
			{
				rb(info->b);
				rb_cnt++;
			}
			printf("aaaa: %d\n", info->pivot_s);
			printf("aaaa: %d\n", info->pivot_b);
			printf("aaaa: %d\n", top_data);
		}
		else
		{
			ra(info->a);
			ra_cnt++;
		}
		s_size--;
		printf("a_to_b\n");
		print_all(info, s_size);
	}
	i = ra_cnt;
	j = rb_cnt;
	while (ra_cnt-- > 0 && rb_cnt-- > 0)
		rrr(info->a, info->b);
	while (ra_cnt-- > 0)
		rra(info->a);
	while (rb_cnt-- > 0)
		rrb(info->b);
	if (!is_sorted(info->a, 0))
		a_to_b(info, i);
	printf("[%d %d]\n", j, pb_cnt-j);
	b_to_a(info, j);
	if (info->b)
		b_to_a(info, pb_cnt - j);
}

void	b_to_a(t_info *info, int s_size)
{
	int     top_data;
	int     ra_cnt;
	int     rb_cnt;
	int     pa_cnt;
	int		i;
	int		j;
	
	if (hard_sort(info, info->b, 1) || s_size <= 0 || is_sorted(info->b, 1))
		return ;
	get_pivot(info, info->b);
	init_cnt(info);
	ra_cnt = 0;
	rb_cnt = 0;
	pa_cnt = 0;
	while (s_size > 0)
	{
		top_data = ft_stacklast(info->b)->data;
		if (top_data < info->pivot_s)
		{
			rb(info->b);
			rb_cnt++;
		}
		else
		{
			pa(info);
			pa_cnt++;
			if (top_data < info->pivot_b)
			{
				ra(info->b);
				ra_cnt++;

			}
		}
		s_size--;
		printf("b_to_a\n");
		print_all(info, s_size);
	}
	i = ra_cnt;
	j = rb_cnt;
	a_to_b(info, pa_cnt - ra_cnt);
	while (ra_cnt-- > 0 && rb_cnt-- != 0)
		rrr(info->a, info->b);
	while (ra_cnt-- > 0)
		rra(info->a);
	while (rb_cnt-- > 0)
		rrb(info->b);
	a_to_b(info, i);
	if (is_sorted(info->b, 1))
		b_to_a(info, j);
}

int	hard_sort(t_info *info, t_stack *s, int flag)
{
	if (ft_stacksize(s) == 1)
		return (1);
	if (ft_stacksize(s) == 2)
		double_sort(info, s, flag);
    else if (ft_stacksize(s) == 3)
		triple_sort(info, s, flag);
    else
		return (0);
	return (1);
}