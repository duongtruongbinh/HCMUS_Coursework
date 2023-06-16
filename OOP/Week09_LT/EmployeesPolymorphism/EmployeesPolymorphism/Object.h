#pragma once
#include <string>
using namespace std;
class Object;

class Object
{
public:
    virtual string toString() = 0;
};