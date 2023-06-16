#pragma once
#include "IParsable.h"
#include "OneSpaceOnly.h"
class OneSpaceOnlyParser;

class OneSpaceOnlyParser :public IParsable
{
public:
	string parsedObjectName();
	Object* parse(string);
	string toString();
};
