/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:48:36 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/05 19:11:42 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Sed.hpp"

int ft_exit(std::string str) {
	std::cout << str << std::endl;
	return (1);
}

int main(int ac, char **av)
{
	Sed sed;
	
	if (ac != 4)
		return (ft_exit("argument error"));
	sed.set_filename(av[1]);
	sed.set_s1(av[2]);
	sed.set_s2(av[3]);
	sed.replace_to_ofs();
}