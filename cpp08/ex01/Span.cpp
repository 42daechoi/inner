#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : N(0)
{
}

Span::Span(unsigned int N) : N(N)
{
}

Span::Span( const Span & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->N = rhs.N;
		this->vec = rhs.vec;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(int value)
{
	if (vec.size() >= N)
		throw std::runtime_error("addNumber() : Span is full.");
	vec.push_back(value);
}

void Span::randomNumSet(void)
{
	std::srand(time(NULL));
	for (unsigned int i = vec.size(); i < N; i++) {
		vec.push_back(rand() % 100);
	}
}

unsigned int Span::shortestSpan(void)
{
	if (vec.size() <= 1)
		throw std::runtime_error("shortestSpan() :Too small size to find span");
	unsigned int min;
	std::vector<int> temp;

	temp = vec;
	std::sort(temp.begin(), temp.end());
	min = UINT_MAX;
	for (unsigned int i = 0; i < temp.size() - 1; i++) {
		if (min > static_cast<unsigned int>(temp[i + 1] - temp[i]))
			min = static_cast<unsigned int>(temp[i + 1] - temp[i]);
	}
	return (min);
}

unsigned int Span::longestSpan(void)
{
	if (vec.size() <= 1)
		throw std::runtime_error("longestSpan() : Too small size to find span");
	std::vector<int> temp;

	temp = vec;
	std::sort(temp.begin(), temp.end());
	return (static_cast<unsigned int>(temp.back() - temp.front()));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::vector<int> Span::getVector(void) const
{
	return (vec);
}

/* ************************************************************************** */