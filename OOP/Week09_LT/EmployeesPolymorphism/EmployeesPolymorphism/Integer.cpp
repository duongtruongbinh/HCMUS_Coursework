#include "Integer.h"

Integer::Integer(int val)
{
	this->_value = val;
}

int Integer::value()
{
	return this->_value;
}

string Integer::toString()
{
	return "Integer";
}