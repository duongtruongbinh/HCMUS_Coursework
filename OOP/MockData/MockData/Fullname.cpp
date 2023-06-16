#include "Fullname.h"
#include <sstream>
using namespace std;

FullName::FullName()
{
	this->_firstName = "";
	this->_lastName = "";
	this->_middleName = "";
}

FullName::FullName(string first, string mid, string last)
{
	this->_lastName = last;
	this->_middleName = mid;
	this->_firstName = first;
}

string FullName::toString()
{
	stringstream builder;
	builder << this->_firstName << " " << this->_middleName << " " << this->_lastName;
	string name = builder.str();
	return name;
}