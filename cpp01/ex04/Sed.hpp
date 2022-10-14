/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daechoi <daechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:56:31 by daechoi           #+#    #+#             */
/*   Updated: 2022/10/05 19:21:14 by daechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
# define SED_H

# include <string>
# include <fstream>
# include <iostream>

class Sed {

public:
	void	set_filename(std::string filename);
	void 	set_s1(std::string s1);
	void 	set_s2(std::string s2);
	void 	replace_to_ofs(void);

private:
	std::string infile;
	std::string outfile;
	std::string s1;
	std::string s2;
	std::ifstream ifs;
	std::ofstream ofs;
};

#endif