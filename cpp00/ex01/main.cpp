/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:56:23 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/04 21:06:14 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	start_prompt(void)
{
	std::string	cmd;
	
	std::cout << "Hello!! This is your own phonebook." << std::endl;
	std::cout << "<Function>\n";
	std::cout << "1. ADD\n";
	std::cout << "2. SEARCH\n";
	std::cout << "3. EXIT\n";
}

int	main(void)
{
	PhoneBook	pb;
	std::string	cmd;

	start_prompt();
	while (1)
	{
		if (!std::cin.good())
			return (0);
		cmd = "";
		std::cout << "> ";
		std::getline(std::cin, cmd);
		if (!std::cin.good())
			return (0);
		if (cmd == "ADD")
			pb.function_add();
		else if (cmd == "SEARCH")
			pb.function_search();
		else if (cmd == "EXIT")
			break ;
	}
	std::cout << "Good Bye.\n";
	return (0);
}