/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:30:37 by kiyoon            #+#    #+#             */
/*   Updated: 2022/12/05 21:16:13 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

int	mouse_hook_bonus(int button, int x, int y, t_set *set)
{
	if (button == 1)
	{
		set->select->mouse_x = x;
		set->select->mouse_y = y;
		select_object_bonus(set);
	}
	return (0);
}

void	set_light(t_set *set)
{
	if (set->select->light->next)
		set->select->light = set->select->light->next;
	else
		set->select->light = set->ele->light;
}

int	key_hook_bonus(int keycode, t_set *set)
{
	move_rotate(keycode, set);
	if (keycode == 53)
	{
		mlx_destroy_window(set->mlx, set->win);
		exit(1);
	}
	else if (keycode == 49)
		set->select->type = CAM;
	else if (keycode == 37)
	{
		set->select->type = LIGHT;
		set_light(set);
	}
	else if (keycode == 24)
		resize(set->select, INCREASE);
	else if (keycode == 27)
		resize(set->select, DECREASE);
	drawing_bonus(set);
	return (0);
}

void	set_keyhook_bonus(t_set *set)
{
	mlx_hook(set->win, X_EVENT_DESTROYNOTIFY, 0, &exit_game, set);
	mlx_key_hook(set->win, key_hook_bonus, set);
	mlx_mouse_hook(set->win, mouse_hook_bonus, set);
}

void	drawing_bonus(t_set *set)
{
	int	count_h;
	int	count_w;

	count_h = HEIGHT;
	count_w = WIDTH;
	while (--count_h >= 0)
	{
		count_w = -1;
		while (++count_w < WIDTH)
			my_mlx_pixel_put_bonus(set->img, count_w, \
				count_h, set->ele);
	}
	mlx_put_image_to_window(set->mlx, set->win, set->img->img_ptr, 0, 0);
}
