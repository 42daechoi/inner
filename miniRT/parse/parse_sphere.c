/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:32:53 by kiyoon            #+#    #+#             */
/*   Updated: 2022/11/08 14:32:54 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static void	insert_last(t_sphere *temp, t_elements *element)
{
	t_sphere	*cur;

	cur = element->sphere;
	element->sphere_cnt++;
	if (!cur)
		element->sphere = temp;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = temp;
	}
}

static bool	is_vaild(t_sphere *ele)
{
	if (ele->red < 0 || ele->red > 255)
		return (false);
	if (ele->green < 0 || ele->green > 255)
		return (false);
	if (ele->blue < 0 || ele->blue > 255)
		return (false);
	return (true);
}

int	parse_sphere(char **buffer, t_elements *element)
{
	t_sphere	*temp;
	char		**position;
	char		**rgb;

	if (split_num(buffer) != 4)
		return (0);
	temp = ft_malloc(sizeof(t_sphere));
	position = ft_split(buffer[1], ", ");
	rgb = ft_split(buffer[3], ", ");
	if (split_num(position) != 3 || split_num(rgb) != 3)
		return (0);
	temp->pos.x = ft_atof(position[0]);
	temp->pos.y = ft_atof(position[1]);
	temp->pos.z = ft_atof(position[2]);
	temp->dia = ft_atof(buffer[2]);
	temp->red = ft_atoi(rgb[0]);
	temp->green = ft_atoi(rgb[1]);
	temp->blue = ft_atoi(rgb[2]);
	temp->next = NULL;
	if (!is_vaild(temp))
		return (0);
	insert_last(temp, element);
	free_char(position);
	free_char(rgb);
	return (1);
}
