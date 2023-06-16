#pragma once
#include <string>
#include <sstream>
using namespace std;

class Shape;

class Shape
{
public:
    
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual string toString()=0;
};