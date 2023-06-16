#pragma once
#include "Shape.h"

class Rectangle;

class Rectangle : public Shape
{
public:
    Rectangle(double, double);
    string toString();
    double area();
    double perimeter();

protected:
    double _width;
    double _height;
};