/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:25:03 by daechoi           #+#    #+#             */
/*   Updated: 2022/06/27 20:42:21 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sort(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->data < stack->next->data)
			return (false);
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
	while (!is_sort(a))
	{
		rra(a);
		if (!is_sort(a))
			sa(a);
	}
}

void	quick_sort(t_stack *a, t_stack *b)
{
	return ;
}

void    sort(t_stack *a, t_stack *b)
{
	if (ft_stacksize(a) < 2)
		return ;
    else if (ft_stacksize(a) == 2)
		double_sort(a);
    else if (ft_stacksize(a) == 3)
		triple_sort(a);
    else
		quick_sort(a, b);
}