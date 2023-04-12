#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN()
{
}

RPN::RPN( const RPN & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	if ( this != &rhs )
	{
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

const char* RPN::WrongExpression::what() const throw()
{
	return "Error: wrong expression";
}


int RPN::calculate(std::string exp) {
	std::stack<int> stack;

	for (int i = 0; i < (int)exp.size(); i++) {
		if (exp[i] == ' ') i++;
		if (isdigit(exp[i]))
			stack.push(exp[i] - 48);
		else if (isOperator(exp[i])) {
			if (stack.size() < 2)
				throw WrongExpression();
			int x, y;
			y = stack.top();
			stack.pop();
			x = stack.top();
			stack.pop();
			if (exp[i] == '+') stack.push(x + y);
			if (exp[i] == '-') stack.push(x - y);
			if (exp[i] == '*') stack.push(x * y);
			if (exp[i] == '/') stack.push(x / y);
		}
		else throw WrongExpression();
	}
	if (stack.size() != 1)
		throw WrongExpression();
	return (stack.top());
}

bool RPN::isOperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */