/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:51:58 by daechoi           #+#    #+#             */
/*   Updated: 2022/11/23 16:46:18 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include <math.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

t_vec3	vec3_set(double x, double y, double z);
double	vec3_length(t_vec3 vec);
double	vec3_distance(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_sub(t_vec3 vec1, t_vec3 vec2);
double	vec3_dot(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_add(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_mul(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_dmul(double d, t_vec3 vec);
t_vec3	vec3_unit(t_vec3 vec);
t_vec3	vec3_min(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec3_cross(t_vec3 vec1, t_vec3 vec2);
double	vec3_length2(t_vec3 vec);

#endif