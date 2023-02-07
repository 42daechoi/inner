/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalization_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:54:38 by kiyoon            #+#    #+#             */
/*   Updated: 2022/12/02 15:54:40 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT_bonus.h"

bool	split_type_bonus(char **temp, t_elements *element, t_set *set)
{
	if (ft_strcmp(temp[0], "A") == 0)
		return (parse_a(temp, element));
	else if (ft_strcmp(temp[0], "C") == 0)
		return (parse_c(temp, element));
	else if (ft_strcmp(temp[0], "L") == 0)
		return (parse_l_bonus(temp, element));
	else if (ft_strcmp(temp[0], "sp") == 0)
		return (parse_sphere_bonus(temp, element, set));
	else if (ft_strcmp(temp[0], "pl") == 0)
		return (parse_plane(temp, element));
	else if (ft_strcmp(temp[0], "cy") == 0)
		return (parse_cylinder(temp, element));
	else if (ft_strcmp(temp[0], "co") == 0)
		return (parse_cone(temp, element));
	else
		return (false);
	return (true);
}

bool	split_newline_bonus(int fd, t_elements *element, t_set *set)
{
	char	*line;
	char	**temp;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_strcmp(line, "") != 0)
		{
			temp = ft_split(line, " ");
			if (!split_type_bonus(temp, element, set))
				return (false);
			free_char(temp);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!element->amb || !element->cam || !element->light)
		return (false);
	return (true);
}

void	init_variable_bonus(t_elements *element)
{
	element->amb = NULL;
	element->cam = NULL;
	element->light = NULL;
	element->sphere = NULL;
	element->plane = NULL;
	element->cylinder = NULL;
	element->cone = NULL;
	element->sphere_cnt = 0;
	element->plane_cnt = 0;
	element->cylinder_cnt = 0;
	element->cone_cnt = 0;
}

bool	init_bonus(int ac, char **av, t_elements *element, t_set *set)
{
	int	fd;

	init_variable_bonus(element);
	if (ac != 2)
		return (false);
	fd = is_end_rt(av[1]);
	if (!fd)
		return (false);
	if (!split_newline_bonus(fd, element, set))
		return (false);
	element->ray = ft_malloc(sizeof(t_ray));
	return (true);
}
