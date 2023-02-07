/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:55:05 by kiyoon            #+#    #+#             */
/*   Updated: 2022/12/12 17:07:42 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vec3	uv_mapping(t_plane *plane, t_hit_record *rec)
{
	t_vec3	unorm;
	t_vec3	vnorm;
	double	u;
	double	v;

	unorm = vec3_cross(plane->norm, vec3_set(1, 0, 0));
	vnorm = vec3_cross(plane->norm, unorm);
	u = fmod(vec3_dot(rec->pos, unorm), 1);
	v = fmod(vec3_dot(rec->pos, vnorm), 1);
	if ((int)(round(u * 2) + round(v * 2)) % 2 == 0)
		return (vec3_set(255, 255, 255));
	return (vec3_set(50, 50, 50));
}

void	hit_pl_bonus(t_elements *ele, t_hit_record *rec, \
						t_ray *ray, t_vec3 *ret)
{
	t_plane	*cur;

	cur = ele->plane;
	while (cur)
	{
		if (hit_plane(cur, ray, rec))
		{
			if (cur->ischeck == 1)
				*ret = uv_mapping(cur, rec);
			else
				*ret = vec3_set(cur->red, cur->green, cur->blue);
			rec->tmax = rec->t;
		}
		cur = cur->next;
	}
}
