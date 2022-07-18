/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:33:46 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/18 16:27:33 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cal_swap(t_stack *stack)
{
	int		temp;
	int		temp2;
	int		i;

	if (ft_stacksize(stack) < 2)
		return ;
	i = 0;
	temp = ft_stacklast(stack)->data;
	while (i < ft_stacksize(stack) - 2)
		stack = stack->next;
	temp2 = stack->data;
	stack->data = temp;
	stack = stack->next;
	stack->data = temp2;
}

void	cal_push(t_stack **giver, t_stack **receiver)
{
	t_stack	*node;

	if (!*giver)
		return ;
	if (!*receiver)
	{
		*receiver = ft_newstack(ft_pop(giver));
		return ;
	}
	node = ft_stacklast(*receiver);
	node->next = ft_newstack(ft_pop(giver));
	node = node->next;
	node->next = NULL;
}

void	cal_rotate(t_stack *stack)
{
	t_stack	*head;
	int		temp;
	int		temp2;

	if (ft_stacksize(stack) == 1)
		return ;
	head = stack;
	temp = stack->data;
	while (stack->next != NULL)
	{
		temp2 = stack->next->data;
		stack->next->data = temp;
		temp = temp2;
		stack = stack->next;
	}
	head->data = temp;
}

void	cal_rev_rotate(t_stack *stack)
{
	t_stack	*tail;
	int		tail_data;

	if (ft_stacksize(stack) == 1)
		return ;
	tail = ft_stacklast(stack);
	tail_data = stack->data;
	while (stack->next != NULL)
	{
		stack->data = stack->next->data;
		stack = stack->next;
	}
	tail->data = tail_data;
}
