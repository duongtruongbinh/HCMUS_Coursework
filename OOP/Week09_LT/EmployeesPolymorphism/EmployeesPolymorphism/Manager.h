#pragma once
#include "Employee.h"

class Manager;

class Manager :public Employee
{
public:
	Manager(int, int, int);
	string toString();
	int salary();
private:
	int _employeeCount;
	int _paymentPerEmployee;
	int _baseSalary;
};