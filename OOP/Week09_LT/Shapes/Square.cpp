#include "Square.h"
#include <sstream>
Square::Square(int a)
{
    this->_a = a;
}

double Square::area()
{
    double result = this->_a * this->_a;
    return result;
}

double Square::perimeter()
{
    double result = this->_a * 4;
    return result;
}

string Square::toString()
{
    stringstream builder;
    builder << "Square a=" << this->_a;
    return builder.str();
}