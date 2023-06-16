#pragma once
#include "Employee.h"

class Worker;

class Worker : public Employee
{
protected:
	int _numItem;
	const int _payPerItem = 20000;
public:
	Worker();
	Worker(int);
	Worker(int, int);
	Worker(int, string, int);
	Worker(int, string, Date, string, int);
public:
	void input();
	void output();
	int salary();
};

