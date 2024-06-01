#ifndef FIXED_HPP
#define FIXED_HPP

class	Fixed
{
	private:
		int					_fixedPoint;
		static const int	_fractionalBits;
	public:
				Fixed(void);
				Fixed(Fixed &toCopy);
		Fixed	&operator=(const Fixed &toCopy);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
				~Fixed( void );
};

#endif