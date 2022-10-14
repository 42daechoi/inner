/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:40:41 by daechoi           #+#    #+#             */
/*   Updated: 2022/09/30 21:06:14 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void) {
	this->name = "";
}

Zombie::~Zombie(void) {
	std::cout << "<" << this->name << ">" << "is dead\n";
}

void Zombie::announce(void) {
	std::cout << "<" << this->name << ">" << "BraiiiiiiinnnzzzZ...\n";
}

void Zombie::set_name(std::string name) {
	this->name = name;
}