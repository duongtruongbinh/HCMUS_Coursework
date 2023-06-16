#include "AddCurrentMonthParser.h"

string AddCurrentMonthParser::parsedObjectName()
{
	return "AddCurrentMonth";
}

string AddCurrentMonthParser::toString()
{
	return "AddCurrentMonthParser";
}

Object* AddCurrentMonthParser::parse(string parameter)
{
	return new AddCurrentMonth();
}