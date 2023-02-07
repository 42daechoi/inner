#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <random>
# include <algorithm>

class Span
{

	public:
		Span();
		Span(unsigned int N);
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );

		void addNumber(int value);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
		void randomNumSet(void);

		std::vector<int> getVector(void) const;
	private:
		unsigned int N;
		std::vector<int> vec;
};

#endif /* ************************************************************ SPAN_H */