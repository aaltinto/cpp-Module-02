#include "Point.hpp"

int main()
{
    Point A(2.32, 4.27);
    Point B(8.96, 9.77);
    Point C(12.96, 5.33);
    Point point1(4, 6);
    Point point2(7, 6);

    std::cout << "point1: ";
    if (bsp(A, B, C, point1) == true)
        std::cout << "true" << std::endl;
    else 
        std::cout << "false" << std::endl;
    std::cout << "point2: ";
    if (bsp(A, B, C, point2) == true)
        std::cout << "true" << std::endl;
    else 
        std::cout << "false" << std::endl;
}