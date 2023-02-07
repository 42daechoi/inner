/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:32:34 by kiyoon            #+#    #+#             */
/*   Updated: 2022/11/23 16:34:58 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	make_float(char *s, float rez, float fact)
{
	int	point_seen;
	int	d;

	point_seen = 0;
	while (*s)
	{
		if (*s == '.')
		{
			point_seen = 1;
			s++;
			continue ;
		}
		d = *s - '0';
		if (d >= 0 && d <= 9)
		{
			if (point_seen)
				fact /= 10.0;
			rez = rez * 10.0 + (double)d;
		}
		s++;
	}
	return (rez * fact);
}

int	is_error(char *s)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '.')
			return (0);
		if (s[i] == '.')
		{
			if (point == 0)
				point = 1;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

double	ft_atof(char *s)
{
	double	rez;
	double	fact;

	rez = 0;
	fact = 1;
	if (*s == '-')
	{
		s++;
		fact = -1;
	}
	if (!is_error(s))
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	return (make_float(s, rez, fact));
}
