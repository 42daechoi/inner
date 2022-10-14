/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:40:33 by daechoi           #+#    #+#             */
/*   Updated: 2022/09/30 21:05:58 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>

class Zombie {
public:
	void announce(void);
	void set_name(std::string name);

	Zombie(void);
	~Zombie(void);
private:
	std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif