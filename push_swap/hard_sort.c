/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:56:42 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/19 21:43:30 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	fifth_sort(t_info *info, t_stack *s, int flag)
// {
// 	int	i;
// 	int	min;
// 	int	max;
// 	int	cnt;

// 	i = 0;
// 	cnt = 0;
// 	min = find_min_max(s, 0, 5);
// 	max = find_min_max(s, 1, 5);
// 	if (flag == 0)
// 	{
// 		while (i < 5)
// 		{
// 			if (get_prev(s, 0)->data == min || get_prev(s, 0)->data == max)
// 				pb(info);
// 			else
// 				ra(s);
// 			i++;
// 		}
// 		if (get_prev(info->b, 1) > get_prev(info->b, 0))
// 			sb(info->b);
// 		pa(info);
// 		while (i-- > 2)
// 			rra(s);
// 		triple_sort(info, s, 0);
// 		pa(info);
// 	}
// 	else
// 	{
// 		while (i < 5)
// 		{
// 			if (get_prev(s, 0)->data == min || get_prev(s, 0)->data == max)
// 			{
// 				pa(info);
// 				cnt++;
// 			}
// 			else
// 				rb(s);
// 			i++;
// 			if (cnt == 2)
// 				break ;
// 		}
// 		if (get_prev(info->a, 1) < get_prev(info->a, 0))
// 			sa(info->a);
// 		ra(info->a);
// 		while (i-- > 2)
// 			rrb(s);
// 		triple_sort(info, s, 1);
// 		rra(info->a);
// 	}
// }

void	a_triple_sort(t_info *info, t_stack *s)
{
	if (find_min_max(s, 0, 3) == get_prev(s, 0)->data)
	{
		pb(info);
		double_sort(info, s, 0);
		pa(info);
	}
	else if (find_min_max(s, 0, 3) == get_prev(s, 1)->data)
	{
		ra(s);
		pb(info);
		rra(s);
		double_sort(info, s, 0);
		pa(info);
	}
	else if (find_min_max(s, 0, 3) == get_prev(s, 2)->data)
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

void	b_triple_sort(t_info *info, t_stack *s)
{
	if (find_min_max(s, 1, 3) == get_prev(s, 0)->data)
	{
		pa(info);
		double_sort(info, s, 1);
	}
	else if (find_min_max(s, 1, 3) == get_prev(s, 1)->data)
	{
		rb(s);
		pa(info);
		rrb(s);
		double_sort(info, s, 1);
	}
	else if (find_min_max(s, 1, 3) == get_prev(s, 2)->data)
	{
		rb(s);
		rb(s);
		pa(info);
		rrb(s);
		rrb(s);
		double_sort(info, s, 1);
	}
}

void	triple_sort(t_info *info, t_stack *s, int flag)
{
	if (flag == 0)
		a_triple_sort(info, s);
	else
		b_triple_sort(info, s);
}

void	double_sort(t_info *info, t_stack *s, int flag)
{
	if (get_prev(s, 0)->data > get_prev(s, 1)->data && flag == 0)
		sa(s);
	if (flag == 1)
	{
		if (get_prev(s, 0)->data < get_prev(s, 1)->data)
			sb(s);
		pa(info);
		pa(info);
	}
}
