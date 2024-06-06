#include "Fixed.hpp"
#include <iostream>

static	float ft_pow(float base, int exp)
{
	float	result;

	if (!exp)
		return (1);
	if (exp < 0)
	{
		base = 1 / base;
		exp *= -1;
	}
	result = base;
	while (--exp)
		result *= base;
	return (result);
}

const int Fixed::_fractionalBits = 8;

Fixed::Fixed ( void ): _fixedPoint(0)
{
	std::cout << "Default constructor called" <<std::endl;
}

Fixed::Fixed ( int const intValue): _fixedPoint(intValue * ft_pow(2, this->_fractionalBits))
{
	std::cout << "Int constructor called" <<std::endl;
}

Fixed::Fixed(float const floatValue): _fixedPoint(floatValue * ft_pow(2, this->_fractionalBits))
{
	std::cout << "Float constructor called" <<std::endl;
}

Fixed::Fixed(Fixed const &toCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}



Fixed  &Fixed::operator=(const Fixed &toCopy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(toCopy.getRawBits());
	return *this;
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fp)
{
	os << fp.toFloat();
	return os;
}

int	Fixed::getRawBits( void ) const
{
	return (this->_fixedPoint);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixedPoint = raw;
}

float	Fixed::toFloat(void) const
{
	return (this->_fixedPoint * ft_pow(2, -this->_fractionalBits));
}

int	Fixed::toInt( void ) const
{
	return (this->_fixedPoint * ft_pow(2, -this->_fractionalBits));
}