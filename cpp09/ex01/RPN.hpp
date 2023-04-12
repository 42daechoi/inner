#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN
{

	public:
		class WrongExpression : public std::exception
		{
			public:
				const char *what() const throw();
		};
		RPN();
		RPN(std::string expression);
		RPN( RPN const & src );
		~RPN();

		RPN &		operator=( RPN const & rhs );

		int calculate(std::string exp);

		bool isOperator(char c);
	private:
};

#endif /* ************************************************************* RPN_H */