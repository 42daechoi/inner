/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:55:11 by daechoi           #+#    #+#             */
/*   Updated: 2022/11/21 14:09:02 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	resize(t_select *select, int flag)
{
	if (select->type == SPHERE && flag == INCREASE)
		select->sp->dia++;
	else if (select->type == CYLINDER && flag == INCREASE)
	{
		select->cy->dia++;
		select->cy->height++;
	}
	else if (select->type == SPHERE && flag == DECREASE)
		select->sp->dia--;
	else if (select->type == CYLINDER && flag == DECREASE)
	{
		select->cy->dia--;
		select->cy->height--;
	}
}
