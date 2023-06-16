#pragma once
#include "IParsable.h"
#include "AddCurrentMonth.h"

class AddCurrentMonthParser;

class AddCurrentMonthParser :public IParsable
{
public:
	string parsedObjectName();
	Object* parse(string);
	string toString();
};
