#pragma once
#include "IParsable.h"
#include "RectangleParser.h"
#include "CircleParser.h"
#include "SquareParser.h"
class ParserFactory;

class ParserFactory : public Object
{
public:
    IParsable *create(string);
    string toString();
};