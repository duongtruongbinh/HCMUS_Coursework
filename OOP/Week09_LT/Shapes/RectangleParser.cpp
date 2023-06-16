#include "RectangleParser.h"

Object *RectangleParser::parse(string parameter)
{
    vector<string> token = Utils::String::split(parameter, ", ");
    int width = stoi(Utils::String::split(token[0], "=")[1]);
    int height = stoi(Utils::String::split(token[1], "=")[1]);
    return new Rectangle(width, height);
}
string RectangleParser::toString()
{
    return "RectangleParser";
}