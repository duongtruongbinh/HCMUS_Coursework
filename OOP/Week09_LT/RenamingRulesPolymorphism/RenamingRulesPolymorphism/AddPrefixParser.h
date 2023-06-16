#pragma once
#include "IParsable.h"
#include "AddPrefix.h"
class AddPrefixParser;

class AddPrefixParser :public IParsable
{
public:
	string parsedObjectName();
	Object* parse(string);
	string toString();
};
