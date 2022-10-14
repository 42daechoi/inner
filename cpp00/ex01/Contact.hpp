/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:58:20 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/04 18:55:13 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact {

public:
	void		set_firstname(std::string first_name);
	void		set_lastname(std::string last_name);
	void		set_nickname(std::string nickname);
	void		set_phonenumber(std::string phone_number);
	void		set_darkestsecret(std::string darkest_secret);
	void		print_list(void);
	std::string	checklen(std::string data);
	void		print_summary(int pb_cnt);

private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

#endif