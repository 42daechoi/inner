/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:10:27 by daechoi           #+#    #+#             */
/*   Updated: 2022/06/29 17:45:58 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	cal_swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	cal_swap(stack);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	cal_swap(a);
	cal_swap(b);
	write(1, "ss\n", 3);
}

void	pa(t_info *info)
{
	cal_push(&(info->b), &(info->a));
	write(1, "pa\n", 3);
}

void	pb(t_info *info)
{
	cal_push(&(info->a), &(info->b));
	write(1, "pb\n", 3);
}