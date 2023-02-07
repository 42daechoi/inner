/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:21:08 by kiyoon            #+#    #+#             */
/*   Updated: 2022/11/22 15:21:08 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

double	minf(double a, double b)
{
	if (a > b)
		return (b);
	return (a);
}

double	maxf(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

void	free_list(t_elements *ele)
{
	t_sphere	*sphere_temp;
	t_cylinder	*cylinder_temp;
	t_plane		*plane_temp;

	while (ele->sphere != NULL)
	{
		sphere_temp = ele->sphere;
		ele->sphere = ele->sphere->next;
		free(sphere_temp);
	}
	while (ele->cylinder != NULL)
	{
		cylinder_temp = ele->cylinder;
		ele->cylinder = ele->cylinder->next;
		free(cylinder_temp);
	}
	while (ele->plane != NULL)
	{
		plane_temp = ele->plane;
		ele->plane = ele->plane->next;
		free(plane_temp);
	}
}

void	free_all(t_elements *ele, t_set *set)
{
	free(ele->amb);
	free(ele->cam);
	free(ele->light);
	free(ele->ray);
	free(set->select);
	free_list(ele);
}
