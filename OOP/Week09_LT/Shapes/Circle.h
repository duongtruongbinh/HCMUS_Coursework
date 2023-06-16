#pragma once
#include "IShape.h"

class Circle;

class Circle : public IShape
{
public:
    Circle(int);

public:
    double area();
    double perimeter();
    string toString();

private:
    int _radius;
    const double _PI = 3.14;
};