/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:30:33 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/04 22:05:12 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType(void) {
	return (this->type);
}

void  Weapon::setType(std::string type) {
	this->type = type;
}

Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::Weapon(void) {}