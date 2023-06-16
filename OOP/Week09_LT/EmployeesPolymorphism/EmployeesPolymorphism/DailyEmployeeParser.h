#pragma once
#include "IParsable.h"

class DailyEmployeeParser;

class DailyEmployeeParser : public IParsable
{
public:
	string parsedObjectName();
	Object* parse(string);
	string toString();
};