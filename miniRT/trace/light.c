/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:10:03 by daechoi           #+#    #+#             */
/*   Updated: 2022/12/07 22:32:14 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (vec3_sub(v, vec3_dmul(vec3_dot(v, n) * 2, n)));
}

bool	in_shadow(t_elements *ele, t_ray *light_ray, double light_length)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_length;
	if (hit(ele, &rec, light_ray).x != -1)
		return (true);
	return (false);
}

t_vec3	point_light(t_elements *ele, t_hit_record *rec)
{
	t_vec3	diffuse;
	t_vec3	light_dir;
	double	ratio;
	double	light_length;
	t_ray	light_ray;

	light_dir = vec3_unit(vec3_sub(ele->light->pos, rec->pos));
	ratio = fmax(vec3_dot(rec->norm, light_dir), 0.05);
	diffuse = vec3_dmul(ratio, vec3_set((double)ele->light->red / 255, \
		(double)ele->light->green / 255, (double)ele->light->blue / 255));
	light_length = vec3_length(light_dir);
	light_ray.pos = vec3_add(rec->pos, vec3_dmul(EPSILON, rec->norm));
	light_ray.dir = vec3_sub(ele->light->pos, rec->pos);
	if (in_shadow(ele, &light_ray, light_length))
		return (vec3_set(0, 0, 0));
	return (diffuse);
}

t_vec3	phong_light(t_elements *ele, t_hit_record *rec)
{
	t_vec3	ret;
	t_vec3	ambient;

	ambient = vec3_dmul(ele->amb->ratio, vec3_set((double)ele->amb->red / 255, \
		(double)ele->amb->green / 255, (double)ele->amb->blue / 255));
	ret = vec3_set((double)ele->light->red / 255, \
		(double)ele->light->green / 255, (double)ele->light->blue / 255);
	ret = vec3_dmul(0.3, ret);
	ret = vec3_add(ret, point_light(ele, rec));
	ret = vec3_add(ret, ambient);
	return (vec3_min(vec3_dmul(ele->light->ratio, ret), vec3_set(1, 1, 1)));
}
