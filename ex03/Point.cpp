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
}

