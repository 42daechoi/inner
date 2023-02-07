/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:57:39 by daechoi           #+#    #+#             */
/*   Updated: 2022/11/21 15:48:02 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector3.h"

t_vec3	vec3_set(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

double	vec3_length(t_vec3 vec)
{
	return (sqrt(pow(vec.x, 2.0) + pow(vec.y, 2.0) + pow(vec.z, 2.0)));
}

double	vec3_distance(t_vec3 vec1, t_vec3 vec2)
{
	return (sqrt(pow(vec1.x - vec2.x, 2.0) + pow((vec1.y - vec2.y), 2.0) \
			+ pow((vec1.z - vec2.z), 2.0)));
}

t_vec3	vec3_sub(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec;

	vec.x = vec1.x - vec2.x;
	vec.y = vec1.y - vec2.y;
	vec.z = vec1.z - vec2.z;
	return (vec);
}

double	vec3_dot(t_vec3 vec1, t_vec3 vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}
