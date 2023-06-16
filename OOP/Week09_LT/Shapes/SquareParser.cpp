#include "SquareParser.h"

Object *SquareParser::parse(string parameter)
{
    int a = stoi(Utils::String::split(parameter, "=")[1]);
    return new Square(a);
}
string SquareParser::toString()
{
    return "SquareParser";
}
