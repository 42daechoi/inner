/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:15:06 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/11 17:27:35 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level) {
	void (Harl::*f[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levelstring[4] = { "debug", "info", "warning" , "error" };
	
	for (int i = 0; i < 4; i++) {
		if (levelstring[i] == level)
			(this->*f[i])();
	}
}

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese \
-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for \
years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}