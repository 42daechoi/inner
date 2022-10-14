/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:09:02 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/05 19:32:09 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void Sed::set_filename(std::string filename) {
	infile = filename;
	ifs.open(infile);
	if (ifs.fail()) {
		std::cout << "file open error" << std::endl;
		exit(1);
	}
	outfile = infile.append(".replace");
}

void Sed::set_s1(std::string s1) {
	if (s1 == "") {
		std::cout << "s1 is empty." << std::endl;
		exit(1);
	}
	this->s1 = s1;
}

void Sed::set_s2(std::string s2) {
	if (s2 == "") {
		std::cout << "s2 is empty." << std::endl;
		exit(1);
	}
	this->s2 = s2;
}

void Sed::replace_to_ofs(void) {
	std::string line;
	int       	s1_pos = -1;
	
	ofs.open(outfile);
	if (ofs.fail()) {
		std::cout << "file open error" << std::endl;
		exit(1);
	}
	std::getline(ifs, line);
	while (!ifs.eof()) {
		while ((s1_pos = line.find(s1)) != -1) {
			if (s1_pos >= 0) {
				line.erase(s1_pos, s1.length());
				line.insert(s1_pos, s2);
			}
		}
		ofs << line << std::endl;
		std::getline(ifs, line);
	}
	while ((s1_pos = line.find(s1)) != -1) {
		if (s1_pos >= 0) {
			line.erase(s1_pos, s1.length());
			line.insert(s1_pos, s2);
		}
	}
	ofs << line;
}