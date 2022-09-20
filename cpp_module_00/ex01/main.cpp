/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:56:23 by daechoi           #+#    #+#             */
/*   Updated: 2022/09/16 23:09:26 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string	start_prompt(void)
{
	std::string	cmd;
	
	std::cout << "Hello!! This is your own phonebook." << std::endl;
	std::cout << "<Function>\n";
	std::cout << "1. ADD\n";
	std::cout << "2. SEARCH\n";
	std::cout << "3. EXIT\n";
	std::cout << "> ";
	std::getline(std::cin, cmd);
	return (cmd);
}

Phonebook	function_add(int pb_num)
{
	Phonebook	pb;
	std::string	input;

	std::cout << "Add new list NUMBER[" << pb_num % 8 << "]\n";
	std::cout << "First name : ";
	std::getline(std::cin, input);
	pb.set_firstname(input);
	std::cout << "Last name : ";
	std::getline(std::cin, input);
	pb.set_lastname(input);
	std::cout << "Nickname : ";
	std::getline(std::cin, input);
	pb.set_nickname(input);
	std::cout << "Phone number : ";
	std::getline(std::cin, input);
	pb.set_phonenumber(input);
	std::cout << "Darkest secret : ";
	std::getline(std::cin, input);
	pb.set_darkestsecret(input);
	std::cout << "NUMBER[" << pb_num % 8 << "] created successly.\n";
	return (pb);
}

void	function_search(Phonebook pb[8], int pb_num)
{
	int	list_cnt;
	int	pb_idx;

	if (pb_num < 8)
		list_cnt = pb_num - 1;
	else
		list_cnt = 8;
	for (int i = 0; i < list_cnt; i++)
		pb[i].print_summary(pb_num);
	std::cout << "Select the list NUMBER(1 ~ " << list_cnt << ").\n";
	std::cout << "NUMBER : ";
	std::cin >> pb_idx;
	while (!(0 < pb_idx && pb_idx <= list_cnt))
	{
		std::cout << "Wrong NUMBER. Please select the list number between 1 to " << list_cnt << std::endl;
		std::cout << "NUMBER : ";
		std::cin >> pb_idx;
	}
	std::cout << "\nSearch result\n\n";
	pb[pb_idx - 1].print_list();
}

int	main(void)
{
	Phonebook	pb[8];
	int			pb_num;
	std::string	cmd;

	pb_num = 1;
	cmd = start_prompt();
	while (cmd != "EXIT")
	{
		if (cmd == "ADD") {
			pb[(pb_num - 1) % 8] = function_add(pb_num);
			pb_num++;
		}
		else if (cmd == "SEARCH")
			function_search(pb, pb_num);
		std::cout << "> ";
		std::getline(std::cin, cmd);
	}
	std::cout << "Good Bye.\n";
	return (0);
}