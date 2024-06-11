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
        Fixed   get_x() const;
        Fixed   get_y() const;
        void    set_x(Fixed x);
        void    set_y(Fixed y);
};

bool    bsp(Point const A, Point const B, Point const C, Point const point);