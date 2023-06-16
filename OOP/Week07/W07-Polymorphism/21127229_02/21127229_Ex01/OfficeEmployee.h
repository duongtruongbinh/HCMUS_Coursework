#pragma once
#include "Employee.h"

class OfficeEmployee;

class OfficeEmployee: public Employee
{
protected:
	int _workDay;
	const int _payPerDay=300000;
public:
	OfficeEmployee();
	OfficeEmployee(int);
	OfficeEmployee(int, int);
	OfficeEmployee(int, string, int);
	OfficeEmployee(int, string, Date, string, int);
public:
	void input();
	void output();
	int salary();
};
