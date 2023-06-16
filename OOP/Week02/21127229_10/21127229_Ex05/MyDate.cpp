#include "MyDate.h"
#include <iostream>

using namespace std;

MyDate::MyDate()
{
	this->_day = 1;
	this->_month = 1;
	this->_year = 2000;
}

MyDate::MyDate(int day)
{
	if (isValidDate(day, 1, 2000) == false)
	{
		day = 1;
	}
	this->_day = day;
	this->_month = 1;
	this->_year = 2000;
}

MyDate::MyDate(int day, int month)
{
	if (isValidDate(day, month, 2000) == false)
	{
		day = 1;
		month = 1;
	}
	this->_day = day;
	this->_month = month;
	this->_year = 2000;
}

MyDate::MyDate(int day, int month,int year)
{
	if (isValidDate(day, month, year) == false)
	{
		day = 1;
		month = 1;
		year = 2000;
	}
	this->_day = day;
	this->_month = month;
	this->_year = year;
}

MyDate::MyDate(const MyDate& other)
{
	this->_day = other._day;
	this->_month = other._month;
	this->_year = other._year;
}

MyDate& MyDate::operator=(const MyDate& other)
{
	this->_day = other._day;
	this->_month = other._month;
	this->_year = other._year;
	return *this;
}

MyDate::~MyDate()
{
	cout << "An object of class MyDate has been removed." << endl;
}

bool MyDate::isLeapYear(int year)
{
	bool result;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		result = true;
	else result = false;
	return result;
}

int MyDate::getMaxDay(int month,int year)
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

void MyDate::display()
{
	
	cout << this->_day << "/" << this->_month << "/" << this->_year<<endl;
	
}

bool MyDate::isValidDate(int day, int month, int year)
{
	bool result = true;
	if (year < 0) result = false;
	if (month > 12 || month < 1) result = false;
	if (day<1 || day>getMaxDay(month, year)) result = false;
	return result;
}
