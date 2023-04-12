/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:33:41 by daechoi           #+#    #+#             */
/*   Updated: 2023/04/06 19:23:59 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Error: invalid argument.\n";
	else
	{
		std::ifstream	file(av[1]);
		std::string		line;

		if (file.is_open()) {
			while (std::getline(file, line)) {
				if (line == "date | value") 
					continue;
				try {
					BitcoinExchange bce(line);
					bce.checkDate();
					bce.checkValue();
					bce.printExchange();
				} catch (std::exception &e) {
					std::cout << e.what() << std::endl;
				}
			}
		}
		else
			std::cout << "Error: invalid file name.\n";
		file.close();
	}
	return 0;
}