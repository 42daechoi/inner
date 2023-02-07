/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:05:44 by kiyoon            #+#    #+#             */
/*   Updated: 2022/12/02 16:05:45 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

static bool	is_vaild(t_cone *ele)
{
	if (ele->red < 0 || ele->red > 255)
		return (false);
	if (ele->green < 0 || ele->green > 255)
		return (false);
	if (ele->blue < 0 || ele->blue > 255)
		return (false);
	if (ele->normal.x < -1 || ele->normal.x > 1)
		return (false);
	if (ele->normal.y < -1 || ele->normal.y > 1)
		return (false);
	if (ele->normal.z < -1 || ele->normal.z > 1)
		return (false);
	return (true);
}

static void	insert_last(t_cone *temp, t_elements *element)
{
	t_cone	*cur;

	cur = element->cone;
	if (!cur)
		element->cone = temp;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = temp;
	}
}

static void	put_variable(t_cone *temp, char **position, \
					char **norm, char **rgb)
{
	temp->pos.x = ft_atof(position[0]);
	temp->pos.y = ft_atof(position[1]);
	temp->pos.z = ft_atof(position[2]);
	temp->normal.x = ft_atof(norm[0]);
	temp->normal.y = ft_atof(norm[1]);
	temp->normal.z = ft_atof(norm[2]);
	temp->red = ft_atoi(rgb[0]);
	temp->green = ft_atoi(rgb[1]);
	temp->blue = ft_atoi(rgb[2]);
}

int	parse_cone(char **buffer, t_elements *element)
{
	char		**position;
	char		**norm;
	char		**rgb;
	t_cone		*temp;

	if (split_num(buffer) != 6)
		return (0);
	temp = ft_malloc(sizeof(t_cone));
	position = ft_split(buffer[1], ", ");
	norm = ft_split(buffer[2], ", ");
	rgb = ft_split(buffer[5], ", ");
	if (split_num(position) != 3 || split_num(norm) != 3 || split_num(rgb) != 3)
		return (0);
	put_variable(temp, position, norm, rgb);
	temp->theta = ft_atof(buffer[3]) * M_PI / 180;
	temp->height = ft_atof(buffer[4]);
	temp->next = NULL;
	if (!is_vaild(temp))
		return (false);
	insert_last(temp, element);
	free_char(position);
	free_char(norm);
	free_char(rgb);
	return (1);
}
