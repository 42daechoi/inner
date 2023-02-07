/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:42:15 by daechoi           #+#    #+#             */
/*   Updated: 2022/11/23 16:46:01 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector3.h"

typedef struct s_ray
{
	t_vec3	pos;
	t_vec3	dir;
}	t_ray;

typedef struct s_hit_record
{
	t_vec3	pos;
	t_vec3	norm;
	double	tmin;
	double	tmax;
	double	t;
	bool	isfront;
	t_vec3	albedo;
}	t_hit_record;

t_vec3	ray_at(t_ray *ray, double t);

#endif
