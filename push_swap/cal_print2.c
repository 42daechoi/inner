/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_print2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:15:36 by daechoi           #+#    #+#             */
/*   Updated: 2022/06/27 20:36:45 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	cal_rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	cal_rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	cal_rotate(a);
	cal_rotate(b);
	write(1, "rr\n", 3);
}

void	rra(t_stack *stack)
{
	cal_rev_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	cal_rev_rotate(stack);
	write(1, "rra\n", 4);
}