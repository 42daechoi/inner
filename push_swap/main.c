/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:30:22 by daechoi           #+#    #+#             */
/*   Updated: 2022/06/20 18:06:51 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_list	*stack;
	t_list	*head;

	if (ac < 2)
		exit(1);
	head = stack;
	stack = ft_lstnew(av[--ac]);
	while (ac > 1)
		ft_lstadd_back(&stack, ft_lstnew(av[--ac]));
	while (stack != NULL)
	{
		printf("%s\n", stack->content);
		stack = stack->next;
	}
}