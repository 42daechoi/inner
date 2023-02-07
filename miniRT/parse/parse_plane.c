/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:00:09 by kiyoon            #+#    #+#             */
/*   Updated: 2022/11/08 14:00:09 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static void	insert_last(t_plane *temp, t_elements *element)
{
	t_plane	*cur;

	cur = element->plane;
	element->plane_cnt++;
	if (!cur)
		element->plane = temp;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = temp;
	}
}

static bool	is_vaild(t_plane *ele)
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

static void	put_variable(t_plane *temp, char **position, \
					char **norm, char **rgb)
{
	temp->ischeck = 0;
	temp->pos.x = ft_atof(position[0]);
	temp->pos.y = ft_atof(position[1]);
	temp->pos.z = ft_atof(position[2]);
	temp->norm.x = ft_atof(norm[0]);
	temp->norm.y = ft_atof(norm[1]);
	temp->norm.z = ft_atof(norm[2]);
	temp->red = ft_atoi(rgb[0]);
	temp->green = ft_atoi(rgb[1]);
	temp->blue = ft_atoi(rgb[2]);
	temp->next = NULL;
}

int	parse_plane(char **buffer, t_elements *element)
{
	char	**position;
	char	**norm;
	char	**rgb;
	t_plane	*temp;

	if (split_num(buffer) != 4)
		return (0);
	temp = ft_malloc(sizeof(t_plane));
	position = ft_split(buffer[1], ", ");
	norm = ft_split(buffer[2], ", ");
	rgb = ft_split(buffer[3], ", ");
	if (split_num(position) != 3 || split_num(norm) != 3 || split_num(rgb) != 3)
		return (0);
	put_variable(temp, position, norm, rgb);
	if (!is_vaild(temp))
		return (0);
	insert_last(temp, element);
	free_char(position);
	free_char(norm);
	free_char(rgb);
	return (1);
}
