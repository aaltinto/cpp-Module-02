#include "Point.hpp"

Point::Point( void ): _x(0), _y(0)
{
}

Point::Point(float x, float y): _x(x), _y(y)
{
}

Point::Point(Point const &point): _x(point._x), _y(point._y)
{
}

Point::~Point( void )
{

}

Point   &Point::operator=(Point const &point)
{
    this->_x = point._x;
    this->_y = point._y;
	return *this;
}

Fixed   Point::get_x() const
{
	return this->_x;
}

Fixed   Point::get_y() const
{
	return this->_y;
}

void    Point::set_x(Fixed x)
{
	this->_x = x;
}

void    Point::set_y(Fixed y)
{
	this->_y = y;
}
