/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:25:03 by daechoi           #+#    #+#             */
/*   Updated: 2022/06/29 00:15:15 by daechoi          ###   ########.fr       */
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

int	cal_cnt;
int init_stack_size = 11;

void	quick_sort(t_stack *a, t_stack *b, int pivot)
{
	cal_cnt = 0;
	if (cal_cnt == init_stack_size && is_sorted(b, 'b'))
	{
		pa(a, b);
	}
	else if (cal_cnt == init_stack_size && !is_sorted(b, 'b'))
	{
		sb(b);
		rb(b);
	}
	if (ft_stacklast(a)->data < pivot)
	{
		pb(a, b);
		cal_cnt++;
	}
	else
	{
		ra(a);
		cal_cnt++;
	}
	sort(a, b, pivot);
}

void    sort(t_stack *a, t_stack *b, int pivot)
{
	if (ft_stacksize(a) < 2)
		return ;
    else if (ft_stacksize(a) == 2)
		double_sort(a);
    else if (ft_stacksize(a) == 3)
		triple_sort(a);
    else
		quick_sort(a, b, pivot);
}