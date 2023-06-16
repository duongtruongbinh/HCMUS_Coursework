#pragma once
#include "IParsable.h"
#include "RemoveSpecialChars.h"
class RemoveSpecialCharsParser;

class RemoveSpecialCharsParser :public IParsable
{
public:
	string parsedObjectName();
	Object* parse(string);
	string toString();

};