/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:56:31 by kiyoon            #+#    #+#             */
/*   Updated: 2022/12/12 15:56:32 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

t_vec3	my_mlx_pixel_get(t_xpm *data, int x, int y)
{
	unsigned char	*dst;

	dst = (unsigned char *)(data->addr \
			+ (y * data->line_length \
			+ x * (data->bits_per_pixel / 8)));
	return (vec3_set(((dst[2])), \
				((dst[1])), \
				((dst[0]))));
}

t_vec3	rander_texture_map(t_sphere *sp, t_vec3 p)
{
	t_vec3	normal;
	double	phi;
	double	theta;
	double	u;
	double	v;

	normal = vec3_unit(vec3_sub(p, sp->pos));
	phi = atan2(normal.z, normal.x);
	theta = asin(normal.y);
	u = 1 - (phi + M_PI) / (2 * M_PI);
	v = (theta + M_PI / 2) / M_PI;
	return (my_mlx_pixel_get(&sp->texture, u * (sp->texture.img_w), \
			sp->texture.img_h - v * (sp->texture.img_h)));
}

t_vec3	get_bump_map(t_sphere *sp, t_vec3 p)
{
	t_vec3	normal;
	double	phi;
	double	theta;
	double	u;
	double	v;

	normal = vec3_unit(vec3_sub(p, sp->pos));
	phi = atan2(normal.z, normal.x);
	theta = asin(normal.y);
	u = 1 - (phi + M_PI) / (2 * M_PI);
	v = (theta + M_PI / 2) / M_PI;
	return (my_mlx_pixel_get(&sp->bump, u * (sp->bump.img_w), \
				sp->bump.img_h - v * (sp->bump.img_h)));
}

t_vec3	get_normal_vector(t_sphere *sp, t_hit_record *rec)
{
	t_vec3	u;
	t_vec3	v;
	t_vec3	n;

	u = vec3_unit(vec3_cross(vec3_set(0, 1, EPSILON), rec->norm));
	v = vec3_unit(vec3_cross(rec->norm, u));
	n = vec3_unit(vec3_sub(vec3_dmul(2, get_bump_map(sp, rec->pos)), \
									vec3_set(1, 1, 1)));
	return (vec3_set(vec3_dot(vec3_set(u.x, v.x, rec->norm.x), n), \
				vec3_dot(vec3_set(u.y, v.y, rec->norm.y), n), \
				vec3_dot(vec3_set(u.z, v.z, rec->norm.z), n)));
}
