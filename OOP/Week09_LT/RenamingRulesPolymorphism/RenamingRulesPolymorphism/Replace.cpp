#include "Replace.h"

Replace::Replace(string pattern, string to)
{
	this->_pattern = pattern;
	this->_to = to;
}

string Replace::toString()
{
	return "Replace";
}

string Replace::rename(string name)
{
	int index = name.find(_pattern);
	if (index != -1)
	{
		name.replace(index, _pattern.length(), _to);
	}
	return name;
}