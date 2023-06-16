#include "Rectangle.h"
#include <sstream>
Rectangle::Rectangle(int width, int height)
{
    this->_width = width;
    this->_height = height;
}

double Rectangle::area()
{
    double result = this->_width * this->_height;
    return result;
}

double Rectangle::perimeter()
{
    double result = 2 * (this->_width + this->_height);
    return result;
}
string Rectangle::toString()
{
    stringstream builder;
    builder << "Rectangle w=" << this->_width << ", h=" << this->_height;
    return builder.str();
}