/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:43:46 by daechoi           #+#    #+#             */
/*   Updated: 2022/09/16 23:08:25 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Phonebook::print_list(void)
{
	std::cout << "First name : " << this->first_name << std::endl;
	std::cout << "Last name : " << this->last_name << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Phone number : " << this->phone_number << std::endl;
	std::cout << "Darkest secret : " << this->darkest_secret << std::endl;
	std::cout << "----------------------------------" << std::endl;
}

std::string	Phonebook::checklen(std::string data)
{
	if (data.length() >= 10)
		data = data.substr(0, 9).append(".");
	return (data);
}

void	Phonebook::print_summary(int pb_num) 
{
	std::cout << std::setfill(' ') << std::setw(10) << (pb_num - 1) % 8 << " | ";
	std::cout << std::setfill(' ') << std::setw(10) << checklen(first_name) << " | ";
	std::cout << std::setfill(' ') << std::setw(10) << checklen(last_name) << " | ";
	std::cout << std::setfill(' ') << std::setw(10) << checklen(nickname) << " |\n";
}