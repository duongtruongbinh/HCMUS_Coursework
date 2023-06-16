#include "OneSpaceOnlyParser.h"

string OneSpaceOnlyParser::parsedObjectName()
{
	return "OneSpaceOnly";
}

string OneSpaceOnlyParser::toString()
{
	return "OneSpaceOnlyParser";
}

Object* OneSpaceOnlyParser::parse(string parameter)
{
	return new OneSpaceOnly;
}