#include "RemoveSpecialCharsParser.h"

string RemoveSpecialCharsParser::parsedObjectName()
{
	return "RemoveSpecialChars";
}

string RemoveSpecialCharsParser::toString()
{
	return "RemoveSpecialCharsParser";
}

Object* RemoveSpecialCharsParser::parse(string parameter)
{
	int index = parameter.find_first_of("=");
	string blackList = parameter.substr(index + 1, parameter.length() - index - 1);
	return new RemoveSpecialChars(blackList);
}