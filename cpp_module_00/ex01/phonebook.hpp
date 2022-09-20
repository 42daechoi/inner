/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:38:55 by daechoi           #+#    #+#             */
/*   Updated: 2022/09/16 23:05:07 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <string>
#include <iomanip>

class Phonebook {

private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

public:
	void	set_firstname(std::string first_name) {
		this->first_name = first_name;
	}
	void	set_lastname(std::string last_name) {
		this->last_name = last_name;
	}
	void	set_nickname(std::string nickname) {
		this->nickname = nickname;
	}
	void	set_phonenumber(std::string phone_number) {
		this->phone_number = phone_number;
	}
	void	set_darkestsecret(std::string darkest_secret) {
		this->darkest_secret = darkest_secret;
	}
	void		print_list(void);
	std::string	checklen(std::string data);
	void		print_summary(int pb_cnt);
};