#pragma once
#include "Object.h"
#include <vector>

class IParsable;

class IParsable :public Object
{
public:
	virtual Object* parse(string) = 0;
	virtual string parsedObjectName() = 0;
};