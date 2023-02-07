/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:16:56 by kiyoon            #+#    #+#             */
/*   Updated: 2022/12/07 18:16:59 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

void	free_list_bonus(t_elements *ele)
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

void	free_multi_light(t_elements *ele)
{
	t_light	*light_temp;

	while (ele->light != NULL)
	{
		light_temp = ele->light;
		ele->light = ele->light->next;
		free(light_temp);
	}
}

void	free_all_bonus(t_elements *ele, t_set *set)
{
	free(ele->amb);
	free(ele->cam);
	free(ele->ray);
	free(set->select);
	free_list_bonus(ele);
	free_multi_light(ele);
}
