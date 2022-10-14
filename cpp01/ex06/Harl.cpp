/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:15:06 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/11 17:29:50 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level) {
	void (Harl::*f[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levelstring[4] = { "DEBUG", "INFO", "WARNING" , "ERROR" };
	int i;
	
	for (i = 0; i < 4; i++) {
		if (levelstring[i] == level)
			break ;
	}
	switch (i)
	{
		case 0:
			(this->*f[0])();
			std::cout << std::endl;
		case 1:
			(this->*f[1])();
			std::cout << std::endl;
		case 2:
			(this->*f[2])();
			std::cout << std::endl;
		case 3:
			(this->*f[3])();
			std::cout << std::endl;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese -triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}