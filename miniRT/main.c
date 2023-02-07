/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:58:18 by kiyoon            #+#    #+#             */
/*   Updated: 2022/11/23 16:42:55 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av)
{
	t_elements	ele;
	t_set		set;

	if (!init(ac, av, &ele))
		ft_exit(1);
	set_mlx(&set, &ele);
	drawing(&set);
	set_keyhook(&set);
	print_manual();
	mlx_loop(set.mlx);
	free(set.mlx);
	free_all(&ele, &set);
	return (0);
}
