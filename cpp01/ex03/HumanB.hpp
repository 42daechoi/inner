/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:31:22 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/04 22:35:22 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {

	public:
		void attack(void);
		HumanB(std::string name);
		void setWeapon(Weapon& weapon);

	private:
		std::string name;
		Weapon		*weapon;
};

#endif