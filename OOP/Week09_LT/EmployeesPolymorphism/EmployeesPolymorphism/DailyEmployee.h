#pragma once
#include  "Employee.h"

class DailyEmployee;

class DailyEmployee :public Employee
{
public:
	DailyEmployee(int, int);
	string toString();
	int salary();
private:
	int _dayCount;
	int _paymentPerDay;
};