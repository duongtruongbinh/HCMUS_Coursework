#pragma once
#include "IRule.h"

class RemoveSpecialChars;

class RemoveSpecialChars :public IRule
{
public:
	RemoveSpecialChars(string);
	string toString();
	string rename(string);

private:
	string _blackList;
};