/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:32:32 by daechoi           #+#    #+#             */
/*   Updated: 2022/09/14 15:51:13 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else {
		for (int i = 1; i < ac; i++) {
			for (int j = 0; av[i][j]; j++) {
				std::cout << (char)std::toupper(av[i][j]);
			}
		}
		std::cout << std::endl;
	}
	return (0);
}