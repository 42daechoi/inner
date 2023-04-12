#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string line)
{
	std::vector<std::string> temp;

	this->line = line;
	temp = split(line, '|');
	if (temp.size() != 2 || !isValueDigit(temp.back()))
		throw InvalidInputException();
	this->date = temp.front();
	std::stringstream ssfloat(temp.back());
	ssfloat >> this->value;
	if (ssfloat.fail())
		throw InvalidValueException();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if ( this != &rhs )
	{
		this->line = rhs.getLine();
		this->date = rhs.getDate();
		this->value = rhs.getValue();
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::vector<std::string> BitcoinExchange::split(std::string str, char delim) {
	std::istringstream			iss(str);
	std::string					buffer;
	std::vector<std::string>	res;

	while (getline(iss, buffer, delim))
		res.push_back(buffer);
	return res;
}

bool BitcoinExchange::isDateDigit(std::vector<std::string> vec) {
	unsigned long i;
	for (i = 0; i < vec.size() - 1; i++) {
		for (unsigned long j = 0; j < vec[i].size(); j++) {
			if (!isdigit(vec[i][j]))
				return false;
		}
	}
	if (vec[i][vec[i].size() - 1] != ' ')
		return false;
	for (unsigned long j = 0; j < vec[i].size() - 1; j++) {
		if (!isdigit(vec[i][j]))
			return false;
	}
	return true;
}

bool BitcoinExchange::isValueDigit(std::string value) {
	int dotcnt = 0;

	if (value[0] != ' ')
		return false;
	for (unsigned long i = 1; i < value.size(); i++) {
		if (value[i] == '.')
			dotcnt++;
		if ((!isdigit(value[i]) && value[i] != '.') || dotcnt > 1)
			return false;
	}
	return true;
}

void BitcoinExchange::checkDate() {
	std::vector<std::string>	vecdate;

	vecdate = split(this->date, '-');
	if (vecdate.size() != 3 || !isDateDigit(vecdate))
		throw InvalidInputException();
	std::stringstream ssyear(vecdate.at(0));
	ssyear >> year;
	if (ssyear.fail() || year < 2009 || year > 2023)
		throw InvalidDateException();
	std::stringstream ssmonth(vecdate.at(1));
	ssmonth >> month;
	if (ssmonth.fail() || month < 0 || month > 12)
		throw InvalidDateException();
	std::stringstream ssday(vecdate.at(2));
	ssday >> day;
	if (ssday.fail() || day < 0)
		throw InvalidDateException();
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		if (day > 31)
			throw InvalidDateException();
	if (month == 4 || month == 6 || month == 9 || month == 11)
		if (day > 30)
			throw InvalidDateException();
	if (month == 2 && day > 28)
		throw InvalidDateException();
}

void BitcoinExchange::checkValue() {
	if (this->value <= 0 || this->value > 1000)
		throw InvalidValueException();
}

const char* BitcoinExchange::InvalidDateException::what() const throw()
{
	return "Error: invalid date.";
}

const char* BitcoinExchange::InvalidValueException::what() const throw()
{
	return "Error: invalid value.";
}

const char* BitcoinExchange::InvalidInputException::what() const throw()
{
	return "Error: invalid input.";
}

float BitcoinExchange::calculBtc() {
	std::ifstream				data("./data.csv");
	std::string 				dataline;
	std::vector<std::string>	vecdata;
	float						exchange = -1;

	if (data.is_open()) {
		while (std::getline(data, dataline)) {
			if (dataline == "date,exchange_rate")
				continue ;
			vecdata = split(dataline, ',');
			if (vecdata.at(0) + " " == this->date) {
				std::stringstream ssdata(vecdata.at(1));
				ssdata >> exchange;
				return (value * exchange);
			}
			findLowerDateExchange(vecdata, &exchange);
		}
	}
	else
		std::cout << "Error: data.csv not found\n";
	data.close();
	return (value * exchange);
}

void BitcoinExchange::findLowerDateExchange(std::vector<std::string> vecdata, float *exchange) {
	std::vector<std::string>	temp;
	int 						dyear, dmonth, dday;

	temp = split(vecdata.at(0), '-');
	std::stringstream ssyear(temp.at(0));
	ssyear >> dyear;
	std::stringstream ssmonth(temp.at(1));
	ssmonth >> dmonth;
	std::stringstream ssday(temp.at(2));
	ssday >> dday;
	if (dyear * 10000 + dmonth * 100 + dday < year * 10000 + month * 100 + day)
	{
		std::stringstream ssdata(vecdata.at(1));
		ssdata >> *exchange;
	}
}

void BitcoinExchange::printExchange() {
	std::cout << this->date << " => " << this->value << " = " << this->calculBtc() << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string BitcoinExchange::getLine() const {
	return this->line;
}

std::string BitcoinExchange::getDate() const {
	return this->date;
}

float BitcoinExchange::getValue() const {
	return this->value;
}


/* ************************************************************************** */