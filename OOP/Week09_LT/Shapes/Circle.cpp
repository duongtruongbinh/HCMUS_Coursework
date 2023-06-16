#include "Circle.h"
#include <sstream>
double Circle::area()
{
    double result = _PI * this->_radius * this->_radius;
    return result;
}

double Circle::perimeter()
{
    double result = _PI * 2 * this->_radius;
    return result;
}
Circle::Circle(int radius)
{
    this->_radius = radius;
}

string Circle::toString()
{
    stringstream builder;
    builder << "Circle r=" << this->_radius;
    return builder.str();
}