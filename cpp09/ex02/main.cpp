/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:29:39 by daechoi           #+#    #+#             */
/*   Updated: 2023/04/13 18:20:22 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <sstream>


int main(int ac, char **av)
{
	PmergeMe pmm(ac, av);
	pmm.print();

	std::cout << "sorted list : ";
	pmm.listPrint();
	std::cout << "\n";

	std::cout << "sorted deque : ";
	pmm.dqPrint();
	std::cout << "\n";
}