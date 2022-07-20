/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:20:52 by daechoi           #+#    #+#             */
/*   Updated: 2022/07/20 16:36:34 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info
{
	t_stack	*a;
	t_stack	*b;
	int		pivot_s;
	int		pivot_b;
	int		depth;
}	t_info;

typedef struct s_aqinfo
{
	int	pivot;
	int	i;
	int	j;
	int	temp;
}	t_aqinfo;

typedef struct s_var
{
	int	var;
	int	min;
	int	next_min;
	int	i;
	int	cnt;
	int	max;
	int	ra_cnt;
	int	rb_cnt;
	int	pa_cnt;
	int	pb_cnt;
}	t_var;

t_stack	*ft_newstack(int data);
void	ft_push(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);
int		ft_stacksize(t_stack *lst);
int		ft_pop(t_stack **stack);
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
void	get_pivot(t_info *info, t_stack *stack, int s_size);
int		hard_sort(t_info *info, t_stack *b, int flag);
bool	is_sorted(t_stack *stack, int s_size, int flag);
void	q_sort_a(t_info *info, t_stack *s, int s_size);
void	q_sort_b(t_info *info, t_stack *s, int s_size);
t_stack	*get_prev(t_stack *s, int prev_count);
int		find_min_max(t_stack *s, int flag, int s_size);
void	reverse_in_sort(t_info *info, int ra_cnt, int rb_cnt);
int		err_check(char **av);
void	double_sort(t_info *info, t_stack *s, int flag);
void	triple_sort(t_info *info, t_stack *s, int flag);

#endif