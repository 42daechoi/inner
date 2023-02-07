/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:16:01 by kiyoon            #+#    #+#             */
/*   Updated: 2022/12/12 17:51:45 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

t_vec3	reflect_bonus(t_vec3 v, t_vec3 n)
{
	return (vec3_sub(v, vec3_dmul(vec3_dot(v, n) * 2, n)));
}

bool	in_shadow_bonus(t_elements *ele, t_ray *light_ray, double light_length)
{
	t_hit_record	rec;

	rec.tmin = EPSILON;
	rec.tmax = light_length;
	if (hit_bonus(ele, &rec, light_ray).x != -1)
		return (true);
	return (false);
}

t_vec3	get_specular_bonus(t_elements *ele, t_hit_record *rec, \
							t_vec3 light_dir, t_light *lights)
{
	t_vec3	specular;
	t_vec3	view_dir;
	t_vec3	reflect_dir;
	double	spec;

	view_dir = vec3_unit(vec3_dmul(-1, ele->ray->dir));
	reflect_dir = reflect_bonus(vec3_dmul(-1, light_dir), rec->norm);
	spec = pow(fmax(vec3_dot(view_dir, reflect_dir), 0.0), 64);
	specular = vec3_dmul(spec, vec3_dmul(lights->ratio, \
		vec3_set((double)lights->red / 255, \
		(double)lights->green / 255, (double)lights->blue / 255)));
	return (specular);
}

t_vec3	point_light_bonus(t_elements *ele, t_hit_record *rec, t_light *lights)
{
	t_vec3	diffuse;
	t_vec3	light_dir;
	double	ratio;
	double	light_length;
	t_ray	light_ray;

	light_dir = vec3_unit(vec3_sub(lights->pos, rec->pos));
	ratio = fmax(vec3_dot(rec->norm, light_dir), 0.05);
	diffuse = vec3_dmul(ratio, vec3_set((double)lights->red / 255, \
		(double)lights->green / 255, (double)lights->blue / 255));
	light_length = vec3_length(light_dir);
	light_ray.pos = vec3_add(rec->pos, vec3_dmul(EPSILON, rec->norm));
	light_ray.dir = vec3_sub(lights->pos, rec->pos);
	if (in_shadow_bonus(ele, &light_ray, light_length))
		return (vec3_set(0, 0, 0));
	return (vec3_add(diffuse, get_specular_bonus(ele, rec, light_dir, lights)));
}

t_vec3	phong_light_bonus(t_elements *ele, t_hit_record *rec)
{
	t_vec3	ret;
	t_vec3	ambient;
	t_light	*lights;
	t_vec3	light_color;

	lights = ele->light;
	ambient = vec3_dmul(ele->amb->ratio, vec3_set((double)ele->amb->red / 255, \
		(double)ele->amb->green / 255, (double)ele->amb->blue / 255));
	ret = vec3_set(0, 0, 0);
	while (lights)
	{
		light_color = vec3_set((double)lights->red / 255, \
			(double)lights->green / 255, (double)lights->blue / 255);
		light_color = vec3_dmul(0.3, light_color);
		light_color = vec3_add(light_color, \
			point_light_bonus(ele, rec, lights));
		light_color = vec3_dmul(lights->ratio, light_color);
		ret = vec3_add(light_color, ret);
		lights = lights->next;
	}
	ret = vec3_add(ret, ambient);
	return (vec3_min(ret, vec3_set(1, 1, 1)));
}
