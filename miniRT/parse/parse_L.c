/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_L.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:56:18 by kiyoon            #+#    #+#             */
/*   Updated: 2022/12/05 16:57:13 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	parse_l(char **buffer, t_elements *element)
{
	char	**position;
	char	**rgb;

	if (element->light)
		return (0);
	if (split_num(buffer) != 4)
		return (0);
	position = ft_split(buffer[1], ", ");
	rgb = ft_split(buffer[3], ", ");
	if (split_num(rgb) != 3 || split_num(position) != 3)
		return (0);
	element->light = ft_malloc(sizeof(t_light));
	element->light->pos.x = ft_atof(position[0]);
	element->light->pos.y = ft_atof(position[1]);
	element->light->pos.z = ft_atof(position[2]);
	element->light->ratio = ft_atof(buffer[2]);
	element->light->red = ft_atoi(rgb[0]);
	element->light->green = ft_atoi(rgb[1]);
	element->light->blue = ft_atoi(rgb[2]);
	element->light->next = NULL;
	free_char(position);
	free_char(rgb);
	return (1);
}
