#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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

Fixed::Fixed(float const floatValue): _fixedPoint(roundf(floatValue * ft_pow(2, this->_fractionalBits)))
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
float  Fixed::operator+(const Fixed &fp)
{
	return (this->toFloat() + fp.toFloat());
}
float  Fixed::operator-(const Fixed &fp)
{
	return (this->toFloat() - fp.toFloat());
}
float  Fixed::operator*(const Fixed &fp)
{
	return (this->toFloat() * fp.toFloat());
}
float  Fixed::operator/(const Fixed &fp)
{
	return (this->toFloat() / fp.toFloat());
}

Fixed  Fixed::operator++(int)
{
	Fixed	tmp = *this;
	this->_fixedPoint++;
	return tmp;
}

Fixed  Fixed::operator--(int)
{
	Fixed	tmp = *this;
	this->_fixedPoint--;
	return tmp;
}

Fixed  Fixed::operator++(void)
{
	this->_fixedPoint++;
	return *this;
}

Fixed  Fixed::operator--(void)
{
	this->_fixedPoint++;
	return *this;
}

const Fixed	&Fixed::min(Fixed const &num1, const Fixed &num2)
{
	if (num1.toFloat() < num2.toFloat())
		return num1;
	else
		return num2;
}
Fixed	&Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1.toFloat() < num2.toFloat())
		return num1;
	else
		return num2;
}

const Fixed	&Fixed::max(Fixed const &num1, const Fixed &num2)
{
	if (num1.toFloat() > num2.toFloat())
		return num1;
	else
		return num2;
}
Fixed	&Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1.toFloat() > num2.toFloat())
		return num1;
	else
		return num2;
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