/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:31:13 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/04 22:31:31 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

void HumanB::attack(void) {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name) {
	this->name = name;
}

void HumanB::setWeapon(Weapon& weapon)  {
	this->weapon = &weapon;
}