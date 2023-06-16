#pragma once
#include "Integer.h"

class Employee;

class Employee :public Object
{
public:
	virtual int salary() = 0;
};