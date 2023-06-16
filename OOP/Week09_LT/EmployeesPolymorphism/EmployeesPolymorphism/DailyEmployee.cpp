#include "DailyEmployee.h"

DailyEmployee::DailyEmployee(int day, int payPerDay)
{
	this->_dayCount = day;
	this->_paymentPerDay = payPerDay;
}

int DailyEmployee::salary()
{
	
	return _dayCount * _paymentPerDay;
}

string DailyEmployee::toString()
{
	return "Daily employee";
}