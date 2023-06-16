#pragma once
#include "Shape.h"
using namespace std;

class Circle;

class Circle:public Shape
{
public:
    string toString();
    Circle(double);
    double area();
    double perimeter();

protected:
    const double _PI = 3.14;
    double _radius;
};