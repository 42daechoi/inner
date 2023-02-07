/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:15:01 by kiyoon            #+#    #+#             */
/*   Updated: 2022/11/08 14:15:04 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static void	insert_last(t_cylinder *temp, t_elements *element)
{
	t_cylinder	*cur;

	cur = element->cylinder;
	element->cylinder_cnt++;
	if (!cur)
		element->cylinder = temp;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = temp;
	}
}

static void	put_variable(t_cylinder *temp, char **position, \
					char **norm, char **rgb)
{
	temp->pos.x = ft_atof(position[0]);
	temp->pos.y = ft_atof(position[1]);
	temp->pos.z = ft_atof(position[2]);
	temp->norm.x = ft_atof(norm[0]);
	temp->norm.y = ft_atof(norm[1]);
	temp->norm.z = ft_atof(norm[2]);
	temp->red = ft_atoi(rgb[0]);
	temp->green = ft_atoi(rgb[1]);
	temp->blue = ft_atoi(rgb[2]);
}

static bool	is_vaild(t_cylinder *ele)
{
	if (ele->red < 0 || ele->red > 255)
		return (false);
	if (ele->green < 0 || ele->green > 255)
		return (false);
	if (ele->blue < 0 || ele->blue > 255)
		return (false);
	if (ele->norm.x < -1 || ele->norm.x > 1)
		return (false);
	if (ele->norm.y < -1 || ele->norm.y > 1)
		return (false);
	if (ele->norm.z < -1 || ele->norm.z > 1)
		return (false);
	return (true);
}

int	parse_cylinder(char **buffer, t_elements *element)
{
	char		**position;
	char		**norm;
	char		**rgb;
	t_cylinder	*temp;

	if (split_num(buffer) != 6)
		return (0);
	temp = ft_malloc(sizeof(t_cylinder));
	position = ft_split(buffer[1], ", ");
	norm = ft_split(buffer[2], ", ");
	rgb = ft_split(buffer[5], ", ");
	if (split_num(position) != 3 || split_num(norm) != 3 || split_num(rgb) != 3)
		return (0);
	put_variable(temp, position, norm, rgb);
	temp->dia = ft_atof(buffer[3]);
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
