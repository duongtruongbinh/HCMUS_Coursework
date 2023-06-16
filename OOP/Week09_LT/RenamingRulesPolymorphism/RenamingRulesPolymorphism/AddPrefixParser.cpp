#include "AddPrefixParser.h"

string AddPrefixParser::parsedObjectName()
{
	return "AddPrefix";
}

string AddPrefixParser::toString()
{
	return "AddPrefixParser";
}

Object* AddPrefixParser::parse(string prefix)
{	
	return new AddPrefix(prefix);
}