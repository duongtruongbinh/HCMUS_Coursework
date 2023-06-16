#pragma once
#include "IParsable.h"
#include "Replace.h"
class ReplaceParser;

class ReplaceParser :public IParsable
{
public:
	string parsedObjectName();
	Object* parse(string);
	string toString();
};
