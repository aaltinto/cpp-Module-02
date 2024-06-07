#include "Fixed.hpp"

class   Point
{
    private:
        Fixed   _x;
        Fixed   _y;
    public:
        Point(void);
        Point(float x, float y);
        Point(Point const &point);
        ~Point(void);
        Point   &operator=(Point const &point);
};