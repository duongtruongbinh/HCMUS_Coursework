#pragma once
#include "IParsable.h"

class ManagerParser;

class ManagerParser : public IParsable
{
public:
	Object* parse(string);
	string parsedObjectName();
	string toString();
};