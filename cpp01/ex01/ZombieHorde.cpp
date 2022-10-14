/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 20:30:18 by daechoi           #+#    #+#             */
/*   Updated: 2022/09/30 21:03:38 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombieHorde = new Zombie[N];

	for (int i = 0; i < N ; i++)
		zombieHorde[i].set_name(name);
	return (zombieHorde);
}