#pragma once
#include "Object.h"
class IValueConverter;

class IValueConverter : public Object
{
public:
    virtual string convert(int) = 0;
    string toString() { return "IValueConverter"; }
};