/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:09:43 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/07 16:07:03 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newstack(int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}


void	ft_push(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (stack == NULL || new == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	tail = ft_stacklast(*stack);
	tail->next = new;
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	ft_stacksize(t_stack *stack)
{
	int	cnt;

	cnt = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		cnt++;
	}
	return (cnt);
}

int	ft_pop(t_stack **stack)
{
	t_stack *tail;
	t_stack	*node;
	int		ret;
	int		i;

	i = 0;
	node = *stack;
	tail = ft_stacklast(*stack);
	ret = tail->data;
	if (ft_stacksize(*stack) == 1)
	{
		free(*stack);
		*stack = NULL;
		return (ret);
	}
	tail->data = 0;
	while (i < ft_stacksize(node) - 2)
		node = node->next;
	node->next = NULL;
	free(tail);
	return (ret);
}
