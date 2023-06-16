#pragma once
#include "IParsable.h"
#include "Square.h"
class SquareParser;

class SquareParser : public IParsable
{
public:
    Object *parse(string);
    string toString();
};