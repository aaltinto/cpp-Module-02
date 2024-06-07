#include "Fixed.hpp"
#include <iostream>

int main( void ) {
Fixed a;
Fixed b( 10 );
Fixed c( 42.42f );
Fixed d( b );

a = b + 10.4567f;
std::cout << "a: " << a << "\nb: " << b << "\nd: " << d << std::endl;
std::cout << "a: " << a << "\nc: " << c << std::endl;
if (a > c)
    std::cout << "a greater than c" << std::endl;

c = Fixed(1234.4323f);
std::cout << "a: " << a << "\nc: " << c << std::endl;
if (a == c)
    std::cout << "a and c equal now" << std::endl;

std::cout << "d before: " << d << std::endl;
d = a + b;
std::cout << "d: " << d << "\nb:  " << b << std::endl;

d = d + b;
std::cout << "now d: " << d << std::endl;
a--;
std::cout << "a: " << a << std::endl;
++a;
std::cout << "a: " << a << std::endl;

return 0;
}
