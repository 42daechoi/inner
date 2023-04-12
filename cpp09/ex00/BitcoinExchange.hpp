#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <vector>
# include <sstream>
# include <cctype>
# include <fstream>

class BitcoinExchange
{

	public:
		class InvalidDateException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class InvalidValueException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class InvalidInputException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		BitcoinExchange();
		BitcoinExchange(std::string line);
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();

		BitcoinExchange &operator=( BitcoinExchange const & rhs );

		std::vector<std::string> split(std::string str, char delim);
		bool isValueDigit(std::string value);
		bool isDateDigit(std::vector<std::string> vec);
		void checkDate();
		void checkValue();
		void printExchange();
		float calculBtc();
		void findLowerDateExchange(std::vector<std::string> vecdata, float *exchange);

		std::string getLine() const;
		std::string getDate() const;
		float getValue() const;
	private:
		std::string line;
		std::string date;
		float 		value;
		int 		year;
		int 		month;
		int 		day;
};

#endif /* ************************************************* BITCOINEXCHANGE_H */