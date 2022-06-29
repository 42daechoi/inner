/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:25:03 by daechoi           #+#    #+#             */
/*   Updated: 2022/06/29 17:42:16 by daechoi          ###   ########.fr       */
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

void	quick_sort(t_info *info)
{
	if (info->cal_cnt == info->init_ssize)
		return ;
	if (ft_stacklast(info->a)->data < info->pivot)
		pb(info);
	else
		ra(info->a);
	info->cal_cnt++;
	sort(info);
}

void    sort(t_info *info)
{
	if (ft_stacksize(info->a) < 2)
		return ;
    else if (ft_stacksize(info->a) == 2)
		double_sort(info->a);
    else if (ft_stacksize(info->a) == 3)
		triple_sort(info->a);
    else
		quick_sort(info);
}