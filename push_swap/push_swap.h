/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:20:52 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/06 19:12:29 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <stdio.h>

typedef struct s_stack
{
    int             data;
    struct s_stack  *next;
} t_stack;

typedef struct s_info
{
	t_stack *a;
	t_stack *b;
	int	ra_cnt;
	int rb_cnt;
	int pb_cnt;
	int pa_cnt;
	int	pivot_s;
	int	pivot_b;
} t_info;

t_stack	*ft_newstack(int data);
void	ft_push(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);
int	    ft_stacksize(t_stack *lst);
int	    ft_pop(t_stack **stack);
void	cal_swap(t_stack *stack);
void	cal_push(t_stack **giver, t_stack **receiver);
void	cal_rotate(t_stack *stack);
void	cal_rev_rotate(t_stack *stack);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	pa(t_info *info);
void	pb(t_info *info);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);
void	get_pivot(t_info *info, t_stack *stack);
void	init_cnt(t_info *info);
void	a_to_b(t_info *info, int s_size);
void	b_to_a(t_info *info, int s_size);
int		hard_sort(t_info *info, t_stack *b, int flag);
bool	is_sorted(t_stack *stack);




void	print_all(t_info *info, int s_size);

#endif