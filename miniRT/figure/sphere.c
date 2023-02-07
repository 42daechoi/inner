/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:34:57 by kiyoon            #+#    #+#             */
/*   Updated: 2022/12/12 17:06:12 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	set_isfront(t_ray *ray, t_hit_record *rec)
{
	if (vec3_dot(ray->dir, rec->norm) < 0)
		rec->isfront = true;
	else
	{
		rec->isfront = false;
		rec->norm = vec3_dmul(-1.0, rec->norm);
	}
}

bool	hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
	double	a;
	double	half_b;
	double	c;
	double	sqrtd;
	double	root;

	a = vec3_dot(ray->dir, ray->dir);
	half_b = vec3_dot(vec3_sub(ray->pos, sp->pos), ray->dir);
	c = vec3_dot(vec3_sub(ray->pos, sp->pos), \
			vec3_sub(ray->pos, sp->pos)) - ((sp->dia / 2) * (sp->dia / 2));
	if (half_b * half_b - a * c <= 0)
		return (false);
	sqrtd = sqrt(half_b * half_b - a * c);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || root > rec->tmax)
		return (false);
	rec->t = root;
	if (!cal_root(a, half_b, c, rec))
		return (false);
	rec->pos = ray_at(ray, root);
	rec->norm = vec3_dmul(1 / (sp->dia / 2), vec3_sub(rec->pos, sp->pos));
	set_isfront(ray, rec);
	return (true);
}

void	hit_sp(t_elements *ele, t_hit_record *rec, t_ray *ray, t_vec3 *ret)
{
	t_sphere	*cur;

	cur = ele->sphere;
	while (cur)
	{
		if (hit_sphere(cur, ray, rec))
		{
			*ret = vec3_set(cur->red, cur->green, cur->blue);
			rec->tmax = rec->t;
		}
		cur = cur->next;
	}
}
