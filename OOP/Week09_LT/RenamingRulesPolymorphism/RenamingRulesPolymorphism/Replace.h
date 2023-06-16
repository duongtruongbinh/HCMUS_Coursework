#pragma once
#include "IRule.h"

class Replace;

class Replace :public IRule
{
public:
	Replace(string,string);
	string toString();
	string rename(string);
private:
	string _pattern;
	string _to;
};