#include "AddPrefix.h"

AddPrefix::AddPrefix(string prefix)
{
	this->_prefix = prefix;
}

string AddPrefix::toString()
{
	return "AddPrefix";
}
string AddPrefix::rename(string name)
{
	return _prefix + " " +  name;
}