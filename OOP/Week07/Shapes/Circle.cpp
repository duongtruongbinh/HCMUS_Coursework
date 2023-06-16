#include "Circle.h"

Circle::Circle(double r)
{
    this->_radius = r;
}

double Circle::area()
{
    double result=this->_radius*this->_radius*_PI;
    return result;
}

double Circle::perimeter()
{
    double result=this->_radius*2*_PI;
    return result;
}

string Circle::toString()
{
    stringstream builder;
    builder<<"R = "<<this->_radius;
    return builder.str();
}