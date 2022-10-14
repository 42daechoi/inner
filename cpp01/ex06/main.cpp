/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:06:50 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/06 12:37:57 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int print_err(std::string str)
{
	std::cout << str << std::endl;
	return (1);
}

int main(int ac, char **av)
{
	Harl harl;

	if (ac != 2)
		return (print_err("[ argumend error ]"));
	harl.complain(av[1]);
	return (0);
}