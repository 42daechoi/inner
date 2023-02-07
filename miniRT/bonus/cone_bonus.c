/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:45:11 by kiyoon            #+#    #+#             */
/*   Updated: 2022/12/02 15:45:12 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

bool	hit_circle_cone(t_cone *co, t_ray *ray, t_hit_record *rec)
{
	double	denominator;
	double	numerator;
	double	root;
	t_vec3	normal;
	t_vec3	center;

	normal = vec3_unit(co->normal);
	center = vec3_add(co->pos, vec3_dmul(co->height, normal));
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
	if (vec3_length(vec3_sub(rec->pos, center)) - \
		co->height * tan(co->theta) > EPSILON)
		return (false);
	set_isfront(ray, rec);
	return (true);
}

int	out_of_cone(t_vec3 temp_norm, t_vec3 temp_pos, t_hit_record *rec)
{
	rec->pos = temp_pos;
	rec->norm = temp_norm;
	return (0);
}

int	set_norm(t_cone *co, t_ray *ray, t_hit_record *rec)
{
	rec->norm = vec3_unit(vec3_sub(rec->pos, vec3_add(co->pos, \
		vec3_dmul(vec3_length(vec3_sub(rec->pos, \
			co->pos)) * acos(co->theta), vec3_unit(co->normal)))));
	set_isfront(ray, rec);
	return (1);
}

int	hit_cone(t_cone *co, t_ray *ray, t_hit_record *rec)
{
	t_vec3	ce;
	double	dv;
	double	ce_v;
	t_vec3	temp_norm;
	t_vec3	temp_pos;

	temp_norm = rec->norm;
	temp_pos = rec->pos;
	ce = vec3_sub(ray->pos, co->pos);
	dv = vec3_dot(ray->dir, vec3_unit(co->normal));
	ce_v = vec3_dot(ce, vec3_unit(co->normal));
	if (!cal_root(dv * dv - pow(cos(co->theta), 2),
			dv * ce_v - vec3_dot(ce, ray->dir) * pow(cos(co->theta), 2),
			ce_v * ce_v - vec3_dot(ce, ce) * pow(cos(co->theta), 2), rec))
		return (0);
	rec->pos = ray_at(ray, rec->t);
	if (vec3_dot(vec3_sub(rec->pos, co->pos), vec3_unit(co->normal)) < 0)
		return (out_of_cone(temp_norm, temp_pos, rec));
	if (vec3_length(vec3_sub(rec->pos, co->pos)) * cos(co->theta) > co->height)
	{
		if (!hit_circle_cone(co, ray, rec))
			return (out_of_cone(temp_norm, temp_pos, rec));
		return (1);
	}
	return (set_norm(co, ray, rec));
}

void	hit_co(t_elements *ele, t_hit_record *rec, t_ray *ray, t_vec3 *ret)
{
	t_cone	*cur;

	cur = ele->cone;
	while (cur)
	{
		if (hit_cone(cur, ray, rec))
		{
			*ret = vec3_set(cur->red, cur->green, cur->blue);
			rec->tmax = rec->t;
		}
		cur = cur->next;
	}
}
