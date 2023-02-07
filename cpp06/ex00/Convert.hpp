#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>

class Convert
{

	public:

		Convert();
		Convert(std::string prevString);
		Convert( Convert const & src );
		~Convert();

		Convert &		operator=( Convert const & rhs );

		bool isChar(std::string prevString);
		void toChar(void);
		void toInt(void);
		void toFloat(void);
		void toDouble(void);
		
	private:
		std::string prevString;
		double 		dValue;
};

#endif /* ********************************************************* CONVERT_H */