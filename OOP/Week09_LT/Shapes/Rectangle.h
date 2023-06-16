#pragma once
#include "IShape.h"

class Rectangle;

class Rectangle:public IShape
{

public:
    Rectangle(int, int);

public:
    double area();
    double perimeter();
    string toString();

private:
    double _width;
    double _height;
};