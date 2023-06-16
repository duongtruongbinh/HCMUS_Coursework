#pragma once
#include "IShape.h"

class Square;

class Square : public IShape
{
public:
    Square(int);

public:
    double area();
    double perimeter();
    string toString();
    

private:
    double _a;
};