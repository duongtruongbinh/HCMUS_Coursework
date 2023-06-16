#pragma once
#include "IParsable.h"

class ProductEmployeeParser;

class ProductEmployeeParser :public IParsable
{
public:
	Object* parse(string);
	string parsedObjectName();
	string toString();
};