/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:32:33 by daechoi           #+#    #+#             */
/*   Updated: 2022/12/05 20:02:59 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_select	*init_select(t_camera *cam, t_light *light)
{
	t_select	*select;

	select = ft_malloc(sizeof(t_select));
	select->type = CAM;
	select->cam = cam;
	select->light = light;
	select->sp = NULL;
	select->pl = NULL;
	select->cy = NULL;
	select->co = NULL;
	return (select);
}
