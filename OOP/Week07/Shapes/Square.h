#pragma once
#include "Shape.h"

class Square;

class Square :public Shape
{
public:
    Square(double);
    string toString();
    double area();
    double perimeter();

protected:
    double _edge;
};