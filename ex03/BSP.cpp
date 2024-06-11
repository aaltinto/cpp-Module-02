#include "Point.hpp"

static Fixed areaOfTriangle(Point A, Point B, Point C)
{
    Fixed area;

    area = ((A.get_x() * (B.get_y() - C.get_y())) + (B.get_x() * (C.get_y() - A.get_y())) + (C.get_x() * (A.get_y() - B.get_y()))) / 2;
    
    return area;
}

bool    bsp(Point const A, Point const B, Point const C, Point const point)
{
    Fixed areaABP = areaOfTriangle(A, B, point);
    Fixed areaBCP = areaOfTriangle(B, C, point);
    Fixed areaCAP = areaOfTriangle(C, A, point);

    if ((areaABP > 0 && areaBCP > 0 && areaCAP > 0) || (areaABP < 0 && areaBCP < 0 && areaCAP < 0))
        return true;
    else
        return false;
}
