#include "CircleParser.h"

Object *CircleParser::parse(string parameter)
{
    int radius = stoi(Utils::String::split(parameter, "=")[1]);
    return new Circle(radius);
}

string CircleParser::toString()
{
    return "CircleParser";
}