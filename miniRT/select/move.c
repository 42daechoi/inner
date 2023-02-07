/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:57:31 by daechoi           #+#    #+#             */
/*   Updated: 2022/11/21 18:50:17 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	move_x(t_select *select, int flag)
{
	if (select->type == CAM && flag == INCREASE)
		select->cam->pos.x++;
	else if (select->type == SPHERE && flag == INCREASE)
		select->sp->pos.x++;
	else if (select->type == PLANE && flag == INCREASE)
		select->pl->pos.x++;
	else if (select->type == CYLINDER && flag == INCREASE)
		select->cy->pos.x++;
	else if (select->type == CONE && flag == INCREASE)
		select->co->pos.x++;
	else if (select->type == LIGHT && flag == INCREASE)
		select->light->pos.x++;
	if (select->type == CAM && flag == DECREASE)
		select->cam->pos.x--;
	else if (select->type == SPHERE && flag == DECREASE)
		select->sp->pos.x--;
	else if (select->type == PLANE && flag == DECREASE)
		select->pl->pos.x--;
	else if (select->type == CYLINDER && flag == DECREASE)
		select->cy->pos.x--;
	else if (select->type == CONE && flag == DECREASE)
		select->co->pos.x--;
	else if (select->type == LIGHT && flag == DECREASE)
		select->light->pos.x--;
}

void	move_y(t_select *select, int flag)
{
	if (select->type == CAM && flag == INCREASE)
		select->cam->pos.y++;
	else if (select->type == SPHERE && flag == INCREASE)
		select->sp->pos.y++;
	else if (select->type == PLANE && flag == INCREASE)
		select->pl->pos.y++;
	else if (select->type == CYLINDER && flag == INCREASE)
		select->cy->pos.y++;
	else if (select->type == CONE && flag == INCREASE)
		select->co->pos.y++;
	else if (select->type == LIGHT && flag == INCREASE)
		select->light->pos.y++;
	if (select->type == CAM && flag == DECREASE)
		select->cam->pos.y--;
	else if (select->type == SPHERE && flag == DECREASE)
		select->sp->pos.y--;
	else if (select->type == PLANE && flag == DECREASE)
		select->pl->pos.y--;
	else if (select->type == CYLINDER && flag == DECREASE)
		select->cy->pos.y--;
	else if (select->type == CONE && flag == DECREASE)
		select->co->pos.y--;
	else if (select->type == LIGHT && flag == DECREASE)
		select->light->pos.y--;
}

void	move_z(t_select *select, int flag)
{
	if (select->type == CAM && flag == INCREASE)
		select->cam->pos.z++;
	else if (select->type == SPHERE && flag == INCREASE)
		select->sp->pos.z++;
	else if (select->type == PLANE && flag == INCREASE)
		select->pl->pos.z++;
	else if (select->type == CYLINDER && flag == INCREASE)
		select->cy->pos.z++;
	else if (select->type == CONE && flag == INCREASE)
		select->co->pos.z++;
	else if (select->type == LIGHT && flag == INCREASE)
		select->light->pos.z++;
	if (select->type == CAM && flag == DECREASE)
		select->cam->pos.z--;
	else if (select->type == SPHERE && flag == DECREASE)
		select->sp->pos.z--;
	else if (select->type == PLANE && flag == DECREASE)
		select->pl->pos.z--;
	else if (select->type == CYLINDER && flag == DECREASE)
		select->cy->pos.z--;
	else if (select->type == CONE && flag == DECREASE)
		select->co->pos.z--;
	else if (select->type == LIGHT && flag == DECREASE)
		select->light->pos.z--;
}

void	move_rotate(int keycode, t_set *set)
{
	if (keycode == 2)
		move_x(set->select, INCREASE);
	else if (keycode == 0)
		move_x(set->select, DECREASE);
	else if (keycode == 13)
		move_y(set->select, INCREASE);
	else if (keycode == 1)
		move_y(set->select, DECREASE);
	else if (keycode == 14)
		move_z(set->select, INCREASE);
	else if (keycode == 12)
		move_z(set->select, DECREASE);
	else if (keycode == 15)
		rotate_x(set->select, INCREASE);
	else if (keycode == 3)
		rotate_x(set->select, DECREASE);
	else if (keycode == 17)
		rotate_y(set->select, INCREASE);
	else if (keycode == 5)
		rotate_y(set->select, DECREASE);
	else if (keycode == 16)
		rotate_z(set->select, INCREASE);
	else if (keycode == 4)
		rotate_z(set->select, DECREASE);
}
