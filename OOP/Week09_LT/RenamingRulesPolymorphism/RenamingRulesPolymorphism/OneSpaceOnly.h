#pragma once
#include "IRule.h"

class OneSpaceOnly;

class OneSpaceOnly :public IRule
{
public:
	string toString();
	string rename(string);
private:
	
};