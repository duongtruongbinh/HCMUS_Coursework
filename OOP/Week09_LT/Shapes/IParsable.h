#pragma once
#include "Object.h"
#include "Utils.h"
class IParsable;

class IParsable : public Object
{
public:
    virtual Object *parse(string) = 0;
};