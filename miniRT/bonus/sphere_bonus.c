/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:20:02 by kiyoon            #+#    #+#             */
/*   Updated: 2022/12/09 17:57:07 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

bool	hit_sphere_bonus(t_sphere *sp, t_ray *ray, \
	t_hit_record *rec, t_vec3 *ret)
{
	double	a;
	double	half_b;
	double	c;

	a = vec3_dot(ray->dir, ray->dir);
	half_b = vec3_dot(vec3_sub(ray->pos, sp->pos), ray->dir);
	c = vec3_dot(vec3_sub(ray->pos, sp->pos), \
			vec3_sub(ray->pos, sp->pos)) - ((sp->dia / 2) * (sp->dia / 2));
	if (!cal_root(a, half_b, c, rec))
		return (false);
	rec->pos = ray_at(ray, rec->t);
	rec->norm = vec3_unit(vec3_sub(rec->pos, sp->pos));
	*ret = rander_texture_map(sp, rec->pos);
	rec->norm = get_normal_vector(sp, rec);
	set_isfront(ray, rec);
	return (true);
}

void	hit_sp_bonus(t_elements *ele, t_hit_record *rec, \
	t_ray *ray, t_vec3 *ret)
{
	t_sphere	*cur;

	cur = ele->sphere;
	while (cur)
	{
		if (hit_sphere_bonus(cur, ray, rec, ret))
			rec->tmax = rec->t;
		cur = cur->next;
	}
}
