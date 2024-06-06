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
}

Fixed::Fixed ( int const intValue): _fixedPoint(intValue * ft_pow(2, this->_fractionalBits))
{
}

Fixed::Fixed(float const floatValue): _fixedPoint(floatValue * ft_pow(2, this->_fractionalBits))
{
}

Fixed::Fixed(Fixed const &toCopy)
{
	*this = toCopy;
}

Fixed::~Fixed(void)
{
}



Fixed  &Fixed::operator=(const Fixed &toCopy)
{
	this->setRawBits(toCopy.getRawBits());
	return *this;
}

bool  Fixed::operator<(const Fixed &fp)
{
	if (this->getRawBits() < fp.getRawBits())
		return (true);
	return (false);
}
bool  Fixed::operator>(const Fixed &fp)
{
	if (this->getRawBits() > fp.getRawBits())
		return (true);
	return (false);
}
bool  Fixed::operator>=(const Fixed &fp)
{
	if (this->getRawBits() >= fp.getRawBits())
		return (true);
	return (false);

}
bool  Fixed::operator<=(const Fixed &fp)
{
	if (this->getRawBits() <= fp.getRawBits())
		return (true);
	return (false);
}
bool  Fixed::operator==(const Fixed &fp)
{
	if (this->getRawBits() == fp.getRawBits())
		return (true);
	return (false);
}
bool  Fixed::operator!=(const Fixed &fp)
{
	if (this->getRawBits() == fp.getRawBits())
		return (false);
	return (true);
}
Fixed  &Fixed::operator+(const Fixed &fp)
{
	this->_fixedPoint += fp._fixedPoint;
	return *this;
}
Fixed  &Fixed::operator-(const Fixed &fp)
{
	this->_fixedPoint -= fp._fixedPoint;
	return *this;
}
Fixed  &Fixed::operator*(const Fixed &fp)
{
	this->_fixedPoint *= fp._fixedPoint;
	return *this;
}
Fixed  &Fixed::operator/(const Fixed &fp)
{
	this->_fixedPoint /= fp._fixedPoint;
	return *this;
}

Fixed  &Fixed::operator++(const Fixed &fp)
{

}

Fixed  &Fixed::operator--(const Fixed &fp)
{

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