#include "ReplaceParser.h"

string ReplaceParser::parsedObjectName()
{
	return "Replace";
}

string ReplaceParser::toString()
{
	return "ReplaceParser";
}
Object* ReplaceParser::parse(string parameter)
{
	int index = parameter.find_first_of("=");
	int commaIndex= parameter.find_first_of(",");
	string pattern = parameter.substr(index + 1, commaIndex - index - 1);
	parameter = parameter.substr(commaIndex + 1, parameter.length() - 1 - commaIndex);
	index = parameter.find_first_of("=");
	string to = parameter.substr(index + 1, parameter.length() - index - 1);
	return new Replace(pattern, to);
}