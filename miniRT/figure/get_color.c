/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:22:25 by kiyoon            #+#    #+#             */
/*   Updated: 2022/12/02 17:22:26 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vec3	hit(t_elements *ele, t_hit_record *rec, t_ray *ray)
{
	t_vec3		ret;

	ret = vec3_set(-1, -1, -1);
	hit_sp(ele, rec, ray, &ret);
	hit_pl(ele, rec, ray, &ret);
	hit_cy(ele, rec, ray, &ret);
	return (ret);
}

t_vec3	ray_color(t_elements *ele)
{
	double			t;
	t_hit_record	rec;
	t_vec3			ret;

	rec.tmin = EPSILON;
	rec.tmax = INFINITY;
	ret = hit(ele, &rec, ele->ray);
	if (ret.x != -1)
		ret = vec3_mul(ret, phong_light(ele, &rec));
	else
	{
		t = 0.5 * (vec3_unit(ele->ray->dir).y + 1.0);
		ret = vec3_dmul(255, vec3_add(vec3_dmul((1.0 - t), vec3_set(1, 1, 1)), \
				vec3_dmul(t, vec3_set(0.5, 0.7, 1.0))));
	}
	return (ret);
}

void	fixed_camera(t_camera *cam, t_ray *ray)
{
	double	vp_h;
	double	vp_w;
	double	focal;

	vp_h = 2.0;
	vp_w = ((double)WIDTH / (double)HEIGHT) * vp_h;
	focal = (vp_w / 2.0 * 90) / cam->fov;
	cam->hor = vec3_set(vp_w, 0, 0);
	cam->ver = vec3_set(0, vp_h, 0);
	cam->llc = vec3_set((cam->pos.x - vp_w / 2) \
		+ cam->norm.x, (cam->pos.y - vp_h / 2) \
		+ cam->norm.y, -focal + cam->norm.z);
	ray->pos = cam->pos;
}

void	my_mlx_pixel_put(t_img *img, int x, int y, t_elements *ele)
{
	int		rgb_color;
	char	*dst;
	double	u;
	double	v;
	t_vec3	color;

	u = (double)x / (double)(WIDTH - 1);
	v = (double)y / (double)(HEIGHT - 1);
	fixed_camera(ele->cam, ele->ray);
	ele->ray->dir = vec3_unit(vec3_sub(vec3_add(vec3_add(ele->cam->llc, \
		vec3_dmul(u, ele->cam->hor)), vec3_dmul(v, ele->cam->ver)), \
		ele->ray->pos));
	color = ray_color(ele);
	rgb_color = ((int)color.x << 16) | ((int)color.y << 8) | (int)color.z;
	dst = img->data + (x * (img->bpp / 8)) + ((HEIGHT - y - 1) * img->size_l);
	*(unsigned int *)dst = rgb_color;
}
