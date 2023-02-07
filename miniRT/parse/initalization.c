/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:50:50 by kiyoon            #+#    #+#             */
/*   Updated: 2022/11/21 14:15:31 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	is_end_rt(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] == 't' && file[i - 2] == 'r' && file[i - 3] == '.')
		return (open(file, O_RDONLY));
	else
		return (0);
}

bool	split_type(char **temp, t_elements *element)
{
	if (ft_strcmp(temp[0], "A") == 0)
		return (parse_a(temp, element));
	else if (ft_strcmp(temp[0], "C") == 0)
		return (parse_c(temp, element));
	else if (ft_strcmp(temp[0], "L") == 0)
		return (parse_l(temp, element));
	else if (ft_strcmp(temp[0], "sp") == 0)
		return (parse_sphere(temp, element));
	else if (ft_strcmp(temp[0], "pl") == 0)
		return (parse_plane(temp, element));
	else if (ft_strcmp(temp[0], "cy") == 0)
		return (parse_cylinder(temp, element));
	else
		return (false);
	return (true);
}

bool	split_newline(int fd, t_elements *element)
{
	char	*line;
	char	**temp;

	line = get_next_line(fd);
	while (line)
	{
		if (ft_strcmp(line, "") != 0)
		{
			temp = ft_split(line, " ");
			if (!split_type(temp, element))
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

void	init_variable(t_elements *element)
{
	element->amb = NULL;
	element->cam = NULL;
	element->light = NULL;
	element->sphere = NULL;
	element->plane = NULL;
	element->cylinder = NULL;
	element->sphere_cnt = 0;
	element->plane_cnt = 0;
	element->cylinder_cnt = 0;
	element->cone_cnt = 0;
}

bool	init(int ac, char **av, t_elements *element)
{
	int	fd;

	init_variable(element);
	if (ac != 2)
		return (false);
	fd = is_end_rt(av[1]);
	if (!fd)
		return (false);
	if (!split_newline(fd, element))
		return (false);
	element->ray = ft_malloc(sizeof(t_ray));
	return (true);
}
