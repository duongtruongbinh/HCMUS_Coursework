#pragma once
#include "Object.h"

class Integer;

class Integer : public Object
{
public:
    Integer(int);
    int value();
    string toString();

private:
    int _value;
};
