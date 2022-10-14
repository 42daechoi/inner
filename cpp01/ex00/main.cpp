/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:40:38 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/04 21:18:31 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie daechoi("daechoi");
	Zombie *seokchoi = newZombie("seokchoi");
	
	daechoi.announce();
	seokchoi->announce();
	randomChump("eunjko");
	delete seokchoi;
	return (0);
}