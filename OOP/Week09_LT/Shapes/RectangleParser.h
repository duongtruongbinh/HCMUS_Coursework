#pragma once
#include "IParsable.h"
#include "Rectangle.h"
class RectangleParser;

class RectangleParser : public IParsable
{
public:
    Object *parse(string);
    string toString();
};