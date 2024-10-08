#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int					_fixedPoint;
		static const int	_fractionalBits;
	public:
		//constructors
		Fixed( void );
		Fixed(int const intValue);
		Fixed(float const floatValue);
		Fixed(Fixed const &toCopy);

		//operator overloads
		Fixed	&operator=(const Fixed &toCopy);
		bool	operator<(const Fixed &toCopy);
		bool	operator>(const Fixed &toCopy);
		bool	operator>=(const Fixed &toCopy);
		bool	operator<=(const Fixed &toCopy);
		bool	operator==(const Fixed &toCopy);
		bool	operator!=(const Fixed &toCopy);
		float	operator+(const Fixed &toCopy);
		float	operator-(const Fixed &toCopy);
		float	operator*(const Fixed &toCopy);
		float	operator/(const Fixed &toCopy);
		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);

		//member functions
		float 	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		static Fixed	&min(Fixed &num1, Fixed &num2);
		static const Fixed	&min(Fixed const &num1, Fixed const &num2);
		static Fixed	&max(Fixed &num1, Fixed &num2);
		static const Fixed	&max(Fixed const &num1, Fixed const &num2);

		//destructors
			~Fixed( void );
};
std::ostream	&operator<<(std::ostream &os, const Fixed &fp);
#endif