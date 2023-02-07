/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:44:45 by daechoi           #+#    #+#             */
/*   Updated: 2022/11/23 19:11:24 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

bool	hit_sp_select(t_set *set, t_hit_record *rec, t_ray *ray)
{
	t_sphere	*cur;
	bool		flag;

	cur = set->ele->sphere;
	flag = false;
	while (cur)
	{
		if (hit_sphere(cur, ray, rec))
		{
			flag = true;
			set->select->type = SPHERE;
			set->select->sp = cur;
			rec->tmax = rec->t;
		}
		cur = cur->next;
	}
	return (flag);
}

bool	hit_pl_select(t_set *set, t_hit_record *rec, t_ray *ray)
{
	t_plane	*cur;
	bool	flag;

	cur = set->ele->plane;
	flag = false;
	while (cur)
	{
		if (hit_plane(cur, ray, rec))
		{
			flag = true;
			set->select->type = PLANE;
			set->select->pl = cur;
			rec->tmax = rec->t;
		}
		cur = cur->next;
	}
	return (flag);
}

bool	hit_cy_select(t_set *set, t_hit_record *rec, t_ray *ray)
{
	t_cylinder	*cur;
	bool		flag;

	cur = set->ele->cylinder;
	flag = false;
	while (cur)
	{
		if (hit_cylinder(cur, ray, rec))
		{
			flag = true;
			set->select->type = CYLINDER;
			set->select->cy = cur;
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

	rec.tmin = EPSILON;
	rec.tmax = INFINITY;
	sphit = hit_sp_select(set, &rec, ray);
	plhit = hit_pl_select(set, &rec, ray);
	cyhit = hit_cy_select(set, &rec, ray);
	if (!sphit && !plhit && !cyhit)
		set->select->type = CAM;
}

t_select	*select_object(t_set *set)
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
