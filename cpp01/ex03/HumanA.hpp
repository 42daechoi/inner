/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:31:05 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/04 22:47:26 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {

	public:
		void attack(void);
		HumanA(std::string name, Weapon& weapon);
		
	private:
		std::string name;
		Weapon&		weapon;
};

#endif