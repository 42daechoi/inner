/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:01:56 by daechoi           #+#    #+#             */
/*   Updated: 2022/11/21 15:48:26 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector3.h"

t_vec3	vec3_add(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	ret;

	ret.x = vec1.x + vec2.x;
	ret.y = vec1.y + vec2.y;
	ret.z = vec1.z + vec2.z;
	return (ret);
}

t_vec3	vec3_mul(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	ret;

	ret.x = vec1.x * vec2.x;
	ret.y = vec1.y * vec2.y;
	ret.z = vec1.z * vec2.z;
	return (ret);
}

t_vec3	vec3_dmul(double d, t_vec3 vec)
{
	t_vec3	ret;

	ret.x = vec.x * d;
	ret.y = vec.y * d;
	ret.z = vec.z * d;
	return (ret);
}

t_vec3	vec3_unit(t_vec3 vec)
{
	t_vec3	ret;

	if (!vec3_length(vec))
	{
		ft_putstr_fd("Error: divided by 0\n", 2);
		exit(1);
	}
	ret.x = vec.x / vec3_length(vec);
	ret.y = vec.y / vec3_length(vec);
	ret.z = vec.z / vec3_length(vec);
	return (ret);
}

t_vec3	vec3_min(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	ret;

	if (vec1.x < vec2.x)
		ret.x = vec1.x;
	else
		ret.x = vec2.x;
	if (vec1.y < vec2.y)
		ret.y = vec1.y;
	else
		ret.y = vec2.y;
	if (vec1.z < vec2.z)
		ret.z = vec1.z;
	else
		ret.z = vec2.z;
	return (ret);
}
