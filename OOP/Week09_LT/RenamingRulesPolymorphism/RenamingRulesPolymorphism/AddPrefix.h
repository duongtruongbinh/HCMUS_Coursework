#pragma once
#include "IRule.h"

class AddPrefix;

class AddPrefix :public IRule
{
public:
	AddPrefix(string);
	string toString();
	string rename(string);
private:
	string _prefix;
};