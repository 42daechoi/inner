#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>() : std::stack<T>() { }
		MutantStack<T>( MutantStack<T> const & src ) { *this = src; }
		~MutantStack<T>() { }

		MutantStack &operator=(const MutantStack & rhs) {
			if ( this != &rhs )
				this = rhs;
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator				iter;
  		typedef typename std::stack<T>::container_type::const_iterator			citer;
		typedef typename std::stack<T>::container_type::reverse_iterator		riter;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	criter;

		iter begin() { return (this->c.begin()); }
		iter end() { return (this->c.end()); }
		citer cbegin() { return (this->c.cbegin()); }
		citer cend() { return (this->c.cend()); }
		riter rbegin() { return (this->c.rbegin()); }
		riter rend() { return (this->c.rend()); }
		criter crbegin() { return (this->c.crbegin()); }
		criter crend() { return (this->c.crend()); }


};

#endif