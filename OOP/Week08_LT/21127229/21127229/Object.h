#pragma once
#include <string>
#include <iostream>
using namespace std;
class Object;

class Object
{
public:
    virtual string toString() = 0;
};
