/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:05:20 by kiyoon            #+#    #+#             */
/*   Updated: 2022/12/02 17:05:20 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

bool	hit_co_select(t_set *set, t_hit_record *rec, t_ray *ray)
{
	t_cone	*cur;
	bool	flag;

	cur = set->ele->cone;
	flag = false;
	while (cur)
	{
		if (hit_cone(cur, ray, rec))
		{
			flag = true;
			set->select->type = CONE;
			set->select->co = cur;
			rec->tmax = rec->t;
		}
		cur = cur->next;
	}
	return (flag);
}

static void	ray_select(t_set *set, t_ray *ray)
{
	t_hit_record	rec;
	bool			sphit;
	bool			plhit;
	bool			cyhit;
	bool			cohit;

	rec.tmin = EPSILON;
	rec.tmax = INFINITY;
	sphit = hit_sp_select(set, &rec, ray);
	plhit = hit_pl_select(set, &rec, ray);
	cyhit = hit_cy_select(set, &rec, ray);
	cohit = hit_co_select(set, &rec, ray);
	if (!sphit && !plhit && !cyhit && !cohit)
		set->select->type = CAM;
}

t_select	*select_object_bonus(t_set *set)
{
	t_ray	ray;
	double	u;
	double	v;

	u = (double)set->select->mouse_x / (double)(WIDTH - 1);
	v = (HEIGHT - (double)set->select->mouse_y) / (double)(HEIGHT - 1);
	fixed_camera(set->ele->cam, &ray);
	ray.dir = vec3_unit(vec3_sub(vec3_add(vec3_add(set->ele->cam->llc, \
		vec3_dmul(u, set->ele->cam->hor)), \
		vec3_dmul(v, set->ele->cam->ver)), \
		ray.pos));
	ray_select(set, &ray);
	return (set->select);
}
