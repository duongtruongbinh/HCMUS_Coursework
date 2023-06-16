#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(double width, double height)
{
    width = abs(width);
    height = abs(height);
    this->_height = height;
    this->_width = width;
}

string Rectangle::toString()
{
    stringstream builder;
    builder << "Width = " << this->_width << " || Height = " << this->_height;
    return builder.str();
}

double Rectangle::area()
{
    double result = this->_width * this->_height;
    return result;
}

double Rectangle::perimeter()
{
    double result = (this->_width + this->_height) * 2;
    return result;
}