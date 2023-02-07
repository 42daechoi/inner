/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:31:49 by kiyoon            #+#    #+#             */
/*   Updated: 2022/11/23 19:26:45 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

bool	cal_root(double a, double half_b, double c, t_hit_record *rec)
{
	double	root;
	double	dis;
	double	sqrtd;

	dis = half_b * half_b - a * c;
	if (dis < 0)
		return (false);
	sqrtd = sqrt(dis);
	root = minf((-half_b - sqrtd) / a, (-half_b + sqrtd) / a);
	if (root < rec->tmin || rec->tmax < root)
	{
		root = maxf((-half_b - sqrtd) / a, (-half_b + sqrtd) / a);
		if (root < rec->tmin || rec->tmax < root)
			return (false);
	}
	rec->t = root;
	return (true);
}

static bool	hit_circle(const t_cylinder *cy, t_ray *ray, \
				t_hit_record *rec, int position)
{
	double	denominator;
	double	numerator;
	double	root;
	t_vec3	normal;
	t_vec3	center;

	normal = vec3_dmul(position, vec3_unit(cy->norm));
	center = vec3_add(cy->pos, vec3_dmul(cy->height / 2, normal));
	denominator = vec3_dot(normal, ray->dir);
	if (fabs(denominator) < EPSILON)
		return (false);
	numerator = vec3_dot(vec3_sub(center, ray->pos), normal);
	root = numerator / denominator;
	if (root < rec->tmin || rec->tmax < root)
		return (false);
	rec->t = root;
	rec->pos = ray_at(ray, root);
	rec->norm = normal;
	if (vec3_length(vec3_sub(rec->pos, center)) - cy->dia / 2 > EPSILON)
		return (false);
	set_isfront(ray, rec);
	return (true);
}

int	out_of_cylinder(t_vec3 temp_norm, t_vec3 temp_pos, t_hit_record *rec)
{
	rec->pos = temp_pos;
	rec->norm = temp_norm;
	return (0);
}

int	hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_vec3	uo_c;
	t_vec3	po_c;
	t_vec3	cp;
	t_vec3	temp_norm;
	t_vec3	temp_pos;

	temp_norm = rec->norm;
	temp_pos = rec->pos;
	uo_c = vec3_cross(ray->dir, vec3_unit(cy->norm));
	po_c = vec3_cross(vec3_sub(ray->pos, cy->pos), vec3_unit(cy->norm));
	if (!cal_root(vec3_length2(uo_c), vec3_dot(uo_c, po_c),
			vec3_length2(po_c) - (cy->dia / 2) * (cy->dia / 2), rec))
		return (0);
	rec->pos = ray_at(ray, rec->t);
	cp = vec3_sub(rec->pos, cy->pos);
	if (fabs(vec3_dot(cp, vec3_unit(cy->norm))) > cy->height / 2)
	{
		if (!hit_circle(cy, ray, rec, 1) && !hit_circle(cy, ray, rec, -1))
			return (out_of_cylinder(temp_norm, temp_pos, rec));
		return (1);
	}
	rec->norm = vec3_unit(vec3_sub(cp, vec3_dmul(
					vec3_dot(cp, vec3_unit(cy->norm)), vec3_unit(cy->norm))));
	set_isfront(ray, rec);
	return (1);
}

void	hit_cy(t_elements *ele, t_hit_record *rec, t_ray *ray, t_vec3 *ret)
{
	t_cylinder	*cur;

	cur = ele->cylinder;
	while (cur)
	{
		if (hit_cylinder(cur, ray, rec))
		{
			*ret = vec3_set(cur->red, cur->green, cur->blue);
			rec->tmax = rec->t;
		}
		cur = cur->next;
	}
}
