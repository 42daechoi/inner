/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_C.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:35:01 by kiyoon            #+#    #+#             */
/*   Updated: 2022/11/08 13:35:01 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static bool	is_vaild(t_elements *ele)
{
	if (ele->cam->norm.x < -1 || ele->cam->norm.x > 1)
		return (false);
	if (ele->cam->norm.y < -1 || ele->cam->norm.y > 1)
		return (false);
	if (ele->cam->norm.z < -1 || ele->cam->norm.z > 1)
		return (false);
	if (ele->cam->fov < 0 || ele->cam->fov > 180)
		return (false);
	return (true);
}

int	parse_c(char **buffer, t_elements *element)
{
	char	**position;
	char	**norm;

	if (element->cam)
		return (0);
	if (split_num(buffer) != 4)
		return (0);
	position = ft_split(buffer[1], ", ");
	norm = ft_split(buffer[2], ", ");
	if (split_num(position) != 3 || split_num(norm) != 3)
		return (0);
	element->cam = ft_malloc(sizeof(t_camera));
	element->cam->pos.x = ft_atof(position[0]);
	element->cam->pos.y = ft_atof(position[1]);
	element->cam->pos.z = ft_atof(position[2]);
	element->cam->norm.x = ft_atof(norm[0]);
	element->cam->norm.y = ft_atof(norm[1]);
	element->cam->norm.z = ft_atof(norm[2]);
	element->cam->fov = ft_atof(buffer[3]);
	if (!is_vaild(element))
		return (0);
	free_char(position);
	free_char(norm);
	return (1);
}
