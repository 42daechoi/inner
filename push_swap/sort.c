/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:25:03 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/18 20:04:17 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack, int s_size, int flag)
{
	int i;

	i = 0;
	if (s_size < 2)
		return (true);
	if (flag == 0)
	{
		while (s_size > i)
		{
			if (get_count_prev(stack, i)->data > get_count_prev(stack, i + 1)->data)
				return (false);
			i++;
		}
	}
	else
	{
		while (s_size > i)
		{
			if (get_count_prev(stack, i)->data < get_count_prev(stack, i + 1)->data)
				return (false);
			i++;
		}
	}
	return (true);
}

void	double_sort(t_info *info, t_stack *s, int flag)
{
	
	if (get_count_prev(s, 0)->data > get_count_prev(s, 1)->data && flag == 0)
		sa(s);
	if (flag == 1)
	{
		if (get_count_prev(s, 0)->data < get_count_prev(s, 1)->data)
			sb(s);
		pa(info);
		pa(info);
	}
}

void	triple_sort(t_info *info, t_stack *s, int flag)
{
	if (flag == 0)
	{
		if (find_min_max(s, 0, 3) == get_count_prev(s, 0)->data)
		{
			pb(info);
			double_sort(info, s, 0);
			pa(info);
		}
		else if (find_min_max(s, 0 ,3) == get_count_prev(s, 1)->data)
		{
			ra(s);
			pb(info);
			rra(s);
			double_sort(info, s, 0);
			pa(info);
		}
		else if (find_min_max(s, 0 ,3) == get_count_prev(s, 2)->data)
		{
			ra(s);
			ra(s);
			pb(info);
			rra(s);
			rra(s);
			double_sort(info, s, 0);
			pa(info);
		}
	}
	else
	{
		if (find_min_max(s, 1, 3) == get_count_prev(s, 0)->data)
		{
			pa(info);
			double_sort(info, s, 1);
		}
		else if (find_min_max(s, 1 ,3) == get_count_prev(s, 1)->data)
		{
			rb(s);
			pa(info);
			rrb(s);
			double_sort(info, s, 1);
		}
		else if (find_min_max(s, 1 ,3) == get_count_prev(s, 2)->data)
		{
			rb(s);
			rb(s);
			pa(info);
			rrb(s);
			rrb(s);
			double_sort(info, s, 1);
		}
	}
}

int	find_min_max(t_stack *s, int flag, int s_size)
{
	int var;
	int i;

	i = 0;
	if (flag == 0)
		var = INT_MAX;
	else
		var = INT_MIN;
	while (s_size > 0)
	{
		if (var > get_count_prev(s, i)->data && flag == 0)
			var = get_count_prev(s, i)->data;
		if (var < get_count_prev(s, i)->data && flag == 1)
			var = get_count_prev(s, i)->data;
		i++;
		s_size--;
	}
	return (var);
}

// void	fifth_sort(t_info *info, t_stack *s, int flag)
// {
// 	if (flag == 0)
// 	{
// 		while (s != NULL)
// 		{
// 			max_swap(s);
// 			printf("[%d]", s->data);
// 			s = s->next;
// 		}
// 	}
// 	else
// 	{
// 		while (s != NULL)
// 		{
// 			min_swap(s);
// 			printf("[%d]", s->data);
// 			s = s->next;
// 		}
// 	}
// }

void	do_instruct_a(t_info *info, int s_size)
{
	int	top_data;
	int	ra_cnt;
	int	rb_cnt;
	int	pb_cnt;

	get_pivot(info, info->a, s_size);
	ra_cnt = 0;
	rb_cnt = 0;
	pb_cnt = 0;
	while (s_size > 0)
	{
		top_data = ft_stacklast(info->a)->data;
		if (top_data > info->pivot_b)
		{
			ra(info->a);
			ra_cnt++;
		}
		else
		{
			pb(info);
			pb_cnt++;
			if (top_data >= info->pivot_s)
			{
				rb(info->b);
				rb_cnt++;
			}
		}
		s_size--;
	}
	reverse_in_sort(info, ra_cnt, rb_cnt);
	q_sort_a(info, info->a, ra_cnt);
	q_sort_b(info, info->b, rb_cnt);
	q_sort_b(info, info->b, pb_cnt - rb_cnt);
}

void	reverse_in_sort(t_info *info, int ra_cnt, int rb_cnt)
{
	while (ra_cnt-- > 0 && rb_cnt-- != 0)
		rrr(info->a, info->b);
	while (ra_cnt-- > 0)
		rra(info->a);
	while (rb_cnt-- > 0)
		rrb(info->b);
}

void	do_instruct_b(t_info *info, int s_size)
{
	int	top_data;
	int	ra_cnt;
	int	rb_cnt;
	int	pa_cnt;
	
	get_pivot(info, info->b, s_size);
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
				ra(info->a);
				ra_cnt++;

			}
		}
		s_size--;
	}
	q_sort_a(info, info->a, pa_cnt - ra_cnt);
	reverse_in_sort(info, ra_cnt, rb_cnt);
	q_sort_a(info, info->a, ra_cnt);
	q_sort_b(info, info->b, rb_cnt);
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
	// else if (s_size == 5)
	// {
	// 	fifth_sort(info, s, 0);
	// 	return ;
	// }
	do_instruct_a(info, s_size);
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
	// else if (s_size == 5)
	// {
	// 	fifth_sort(info, s, 1);
	// 	return ;
	// }
	do_instruct_b(info, s_size);
}