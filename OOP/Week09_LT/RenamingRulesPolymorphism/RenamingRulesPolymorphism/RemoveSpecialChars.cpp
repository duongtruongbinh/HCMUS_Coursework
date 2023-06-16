#include "RemoveSpecialChars.h"

RemoveSpecialChars::RemoveSpecialChars(string blacklist)
{
	this->_blackList = blacklist;
}

string RemoveSpecialChars::toString()
{
	return "RemoveSpecialChars";
}

string RemoveSpecialChars::rename(string name)
{
	for (int i = 0; i < name.length(); i++)
	{
		if (_blackList.find(name[i]) != -1)
		{
			name[i] = ' ';
		}
	}
	return name;
}