/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:58:19 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/04 18:49:24 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::print_list(void)
{
	std::cout << "First name : " << this->first_name << std::endl;
	std::cout << "Last name : " << this->last_name << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Phone number : " << this->phone_number << std::endl;
	std::cout << "Darkest secret : " << this->darkest_secret << std::endl;
	std::cout << "----------------------------------" << std::endl;
}

std::string	Contact::checklen(std::string data)
{
	if (data.length() >= 10)
		data = data.substr(0, 9).append(".");
	return (data);
}

void	Contact::print_summary(int number) 
{
	std::cout << std::setfill(' ') << std::setw(10) << number << " | ";
	std::cout << std::setfill(' ') << std::setw(10) << checklen(first_name) << " | ";
	std::cout << std::setfill(' ') << std::setw(10) << checklen(last_name) << " | ";
	std::cout << std::setfill(' ') << std::setw(10) << checklen(nickname) << " |\n";
}

void	Contact::set_firstname(std::string first_name) {
	this->first_name = first_name;
}

void	Contact::set_lastname(std::string last_name) {
	this->last_name = last_name;
}

void	Contact::set_nickname(std::string nickname) {
	this->nickname = nickname;
}

void	Contact::set_phonenumber(std::string phone_number) {
	this->phone_number = phone_number;
}

void	Contact::set_darkestsecret(std::string darkest_secret) {
	this->darkest_secret = darkest_secret;
}