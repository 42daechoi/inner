/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:40:33 by daechoi           #+#    #+#             */
/*   Updated: 2022/09/30 20:14:37 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>

class Zombie {
public:
	void announce(void);

	Zombie(std::string name);
	~Zombie(void);
private:
	std::string name;
};

Zombie* newZombie(std::string name);
void 	randomChump(std::string name);

#endif