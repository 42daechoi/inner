#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{

	public:

		Fixed();
		Fixed(const int n);
		Fixed(const float f);
		Fixed( Fixed const & src );
		~Fixed();

		Fixed	&operator=( Fixed const & rhs );
		bool 	operator>(Fixed const &rhs);
		bool 	operator<(Fixed const &rhs);
		bool 	operator<=(Fixed const &rhs);
		bool 	operator>=(Fixed const &rhs);
		bool 	operator==(Fixed const &rhs);
		bool 	operator!=(Fixed const &rhs);
		Fixed 	operator+(Fixed const &rhs);
		Fixed 	operator-(Fixed const &rhs);
		Fixed 	operator*(Fixed const &rhs);
		Fixed 	operator/(Fixed const &rhs);
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
		static Fixed &max( Fixed &a, Fixed &b );
		static const Fixed &max( Fixed const &a, Fixed const &b );
		static Fixed &min( Fixed &a, Fixed &b );
		static const Fixed &min( Fixed const &a, Fixed const &b );
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int fixed_decimal;
		static const int bits = 8;
};

std::ostream &operator<<( std::ostream &o, Fixed const &i );

#endif /* *********************************************************** FIXED_H */