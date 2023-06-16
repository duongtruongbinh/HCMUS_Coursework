#include "Date.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
using namespace std;

Date::Date()
{
	time_t info = time(NULL);
	tm now;
	localtime_s(&now, &info);

	_year = now.tm_year + 1900;
	_month = now.tm_mon + 1;
	_day = now.tm_mday;
}

Date::Date(int day, int month, int year)
{
	if (isValidDate(day, month, year) == false)
	{
		Date();
		return;
	}
	this->_day = day;
	this->_month = month;
	this->_year = year;
}

bool Date::isLeapYear(int year)
{
	bool result;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		result = true;
	else result = false;
	return result;
}

int Date::getMaxDay(int month, int year)
{
	int maxDay = 31;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		maxDay = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		maxDay = 30;
		break;
	case 2:
		if (isLeapYear(year) == true) maxDay = 29;
		else maxDay = 28;
		break;
	}
	return maxDay;
}

string Date::toString()
{
	stringstream builder;
	builder << setw(2) << setfill('0') << _day << "/"
		<< setw(2) << setfill('0') << _month << "/" << _year;

	return builder.str();
}

bool Date::isValidDate(int day, int month, int year)
{
	bool result = true;
	if (year < 0) result = false;
	if (month > 12 || month < 1) result = false;
	if (day<1 || day>getMaxDay(month, year)) result = false;
	return result;
}