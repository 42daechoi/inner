/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:33:46 by daechoi           #+#    #+#             */
/*   Updated: 2022/06/23 20:16:08 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cal_swap(t_stack *stack)
{
	int		temp;
	int		temp2;
	int		i;

	if (ft_stacksize(stack) <= 2)
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

void	cal_push(t_stack *receiver, t_stack *giver)
{
	t_stack	*head;

	if (!giver)
		return ;
	head = ft_stacklast(receiver);
	head->next = ft_newstack(ft_pop(giver));
	head = head->next;
	head->next = NULL;
}

void	cal_rotate(t_stack **stack)
{
	t_stack	*head;
	
	head = ft_newstack(ft_pop(*stack));
	head->next = *stack;
	*stack = head;
}

void	cal_rev_rotate(t_stack **stack)
{
	t_stack *temp;
	t_stack *head;
	t_stack	*temp2;

	head = *stack;
	*stack = (*stack)->next;
	temp = ft_newstack(head->data);
	head->data = 0;
	head->next = NULL;
	free(head);
	ft_stacklast(*stack)->next = temp;
}