/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:43:46 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/04 21:07:10 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::number = -1;
bool PhoneBook::is_full = false;

void	PhoneBook::function_add(void)
{
	PhoneBook	pb;
	std::string	input;

	number++;
	if (number > 7)
	{
		number = 0;
		is_full = true;
	}
	std::cout << "Add new list NUMBER[" << number << "]\n";
	std::cout << "First name : ";
	std::getline(std::cin, input);
	if (!std::cin.good() || input == "") {
		number--;
		return ;
	}
	contact[number].set_firstname(input);
	std::cout << "Last name : ";
	std::getline(std::cin, input);
	if (!std::cin.good() || input == "") {
		number--;
		return ;
	}
	contact[number].set_lastname(input);
	std::cout << "Nickname : ";
	std::getline(std::cin, input);
	if (!std::cin.good() || input == "") {
		number--;
		return ;
	}
	contact[number].set_nickname(input);
	std::cout << "Phone number : ";
	std::getline(std::cin, input);
	if (!std::cin.good() || input == "") {
		number--;
		return ;
	}
	contact[number].set_phonenumber(input);
	std::cout << "Darkest secret : ";
	std::getline(std::cin, input);
	if (!std::cin.good() || input == "") {
		number--;
		return ;
	}
	contact[number].set_darkestsecret(input);
	std::cout << "NUMBER[" << number << "] created successly.\n";
}

void	PhoneBook::function_search(void)
{
	int	pb_idx;
	std::string cmd;
	int n;

	if (is_full)
		n = 8;
	else
		n = number;
	if (number == -1)
	{
		std::cout << "No list for search. Please search after add.\n";
		return ;
	}
	for (int i = 0; i <= n; i++)
		contact[i].print_summary(i);
	std::cout << "Select the list NUMBER(0 ~ " << n << ").\n";
	std::cout << "NUMBER : ";
	std::getline(std::cin, cmd);
	pb_idx = static_cast<int>(cmd[0] - '0');
	if (cmd[1] || !(0 <= pb_idx && pb_idx <=n))
	{
		std::cout << "Wrong NUMBER. Please select the list number between 0 to " << n << std::endl;
		return ;
	}
	std::cout << "\nSearch result\n\n";
	contact[pb_idx].print_list();
}