#include "Manager.h"

Manager::Manager(int employee, int pay, int base)
{
	this->_employeeCount = employee;
	this->_paymentPerEmployee = pay;
	this->_baseSalary = base;
}

string Manager::toString()
{
	return "Manager";
}

int Manager::salary()
{
	return _employeeCount * _paymentPerEmployee + _baseSalary;
}