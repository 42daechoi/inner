/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:55:05 by kiyoon            #+#    #+#             */
/*   Updated: 2022/12/07 20:07:07 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

bool	hit_plane(t_plane *pl, t_ray *ray, t_hit_record *rec)
{
	double	numrator;
	double	denominator;
	double	root;

	denominator = vec3_dot(ray->dir, pl->norm);
	if (fabs(denominator) < EPSILON)
		return (false);
		numrator = vec3_dot(vec3_sub(pl->pos, ray->pos), pl->norm);
	root = numrator / denominator;
	if (root < rec->tmin || rec->tmax < root)
		return (false);
	rec->t = root;
	rec->pos = ray_at(ray, root);
	rec->norm = pl->norm;
	set_isfront(ray, rec);
	return (true);
}

void	hit_pl(t_elements *ele, t_hit_record *rec, t_ray *ray, t_vec3 *ret)
{
	t_plane	*cur;

	cur = ele->plane;
	while (cur)
	{
		if (hit_plane(cur, ray, rec))
		{
			*ret = vec3_set(cur->red, cur->green, cur->blue);
			rec->tmax = rec->t;
		}
		cur = cur->next;
	}
}
