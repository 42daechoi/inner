/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:31:55 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/04 21:52:48 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>

class Weapon {

public :
	const std::string &getType();
	void  setType(std::string type);
	Weapon(void);
	Weapon(std::string type);

private :
	std::string type;
};

#endif