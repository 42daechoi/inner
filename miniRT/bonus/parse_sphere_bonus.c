/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:01:00 by kiyoon            #+#    #+#             */
/*   Updated: 2022/12/12 17:12:22 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

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

void	parse_xpm(t_sphere *sphere, t_set *set)
{
	sphere->texture.img = mlx_xpm_file_to_image(set->mlx, \
		"./asset/moon_texture.xpm", &sphere->texture.img_w, \
		&sphere->texture.img_h);
	if (sphere->texture.img == NULL)
		ft_exit(1);
	sphere->texture.addr = (unsigned char *)mlx_get_data_addr(\
	sphere->texture.img, &sphere->texture.bits_per_pixel, \
	&sphere->texture.line_length, &sphere->texture.endian);
	sphere->bump.img = mlx_xpm_file_to_image(set->mlx, \
		"./asset/moon_bump2.xpm", &sphere->bump.img_w, &sphere->bump.img_h);
	if (sphere->bump.img == NULL)
		ft_exit(1);
	sphere->bump.addr = (unsigned char *)mlx_get_data_addr(sphere->bump.img, \
	&sphere->bump.bits_per_pixel, \
	&sphere->bump.line_length, &sphere->bump.endian);
	sphere->next = NULL;
}

int	parse_sphere_bonus(char **buffer, t_elements *element, t_set *set)
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
	parse_xpm(temp, set);
	if (!is_vaild(temp))
		return (0);
	insert_last(temp, element);
	free_char(position);
	free_char(rgb);
	return (1);
}
