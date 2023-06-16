#include "Date.h"
#include <ctime>

Date::Date()
{
	time_t info = time(NULL);
	tm now;
	localtime_s(&now, &info);

	this->_year = now.tm_year + 1900;
	this->_month = now.tm_mon + 1;
	this->_day = now.tm_mday;
}

Date::Date(int year)
{
	this->_year = year;
	this->_month = 1;
	this->_day = 1;
}

Date::Date(int year,int month)
{
	this->_year = year;
	this->_month = month;
	this->_day = 1;
}

Date::Date(int year, int month,int day)
{
	this->_year = year;
	this->_month = month;
	this->_day = day;
}

Date::Date(const Date& other)
{
	this->_day = other._day;
	this->_month = other._month;
	this->_year = other._year;
}

Date& Date::operator=(const Date& other)
{

	this->_day = other._day;
	this->_month = other._month;
	this->_year = other._year;
	return *this;
}

bool Date::isLeapYear(int year)const
{
	bool result;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		result = true;
	else result = false;
	return result;
}

int Date::getMaxDay(int month, int year)const
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

Date Date::Tomorrow()
{
	Date tomorrow(*this);
	tomorrow._day = this->_day % getMaxDay(this->_month, this->_year) + 1;
	if (tomorrow._day == 1)
		tomorrow._month = (this->_month % 12) + 1;
	if (tomorrow._day == 1 && tomorrow._month == 1) tomorrow._year = this->_year + 1;
	return tomorrow;
}

Date Date::Yesterday()
{
	Date yesterday(*this);
	if (this->_day == 1)
	{
		yesterday._day = getMaxDay(this->_month - 1,this->_year);
		if (this->_month == 1)
		{
			yesterday._month = 12;
			yesterday._year=this->_year-1;
		}
		else yesterday._month--;
	}
	else yesterday._day = this->_day - 1;
	return yesterday;
}

bool Date::operator==(const Date& other)
{
	bool result;
	result = (this->_day == other._day && this->_month == other._month && this->_year == other._year);
	return result;
}

bool Date::operator!=(const Date& other)
{
	
	return !operator==(other);
}

bool Date::operator>=(const Date& other)
{
	if (this->_year > other._year) return true;
	if (this->_year < other._year) return false;

	if (this->_month > other._month) return true;
	if (this->_month < other._month) return false;

	if (this->_day >= other._day) return true;
	return false;	
}

bool Date::operator>(const Date& other)
{
	if (this->_year > other._year) return true;
	if (this->_year < other._year) return false;

	if (this->_month > other._month) return true;
	if (this->_month < other._month) return false;

	if (this->_day > other._day) return true;
	return false;
}

bool Date::operator<=(const Date& other)
{
	if (this->_year < other._year) return true;
	if (this->_year > other._year) return false;

	if (this->_month < other._month) return true;
	if (this->_month > other._month) return false;

	if (this->_day <= other._day) return true;
	return false;
}

bool Date::operator<(const Date& other)
{
	if (this->_year < other._year) return true;
	if (this->_year > other._year) return false;

	if (this->_month < other._month) return true;
	if (this->_month > other._month) return false;

	if (this->_day < other._day) return true;
	return false;
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << date._day << "/" << date._month << "/" << date._year;
	return os;
}

istream& operator>>(istream& is, Date& date)
{	
	cout << "Day=";
	is >> date._day;
	cout << "Month=";
	is>>date._month;
	cout << "Year=";
	is>>date._year;
	return is;
}

Date& Date::operator++()
{
	*this = this->Tomorrow();
	return *this;
}

Date Date::operator++(int)
{
	Date* date = this;
	*this = this->Tomorrow();
	return *date;
}

Date& Date::operator--()
{
	*this = this->Yesterday();
	return *this;
}

Date Date::operator--(int)
{
	Date* date = this;
	*this = this->Yesterday();
	return *date;
}

Date Date::operator+(const int& num)
{
	Date after;
	for (int i = 1; i <= num; i++)
		after = this->Tomorrow();
	return after;
}

Date Date::operator-(const int& num)
{
	Date before;
	for (int i = 1; i <= num; i++)
		before = this->Yesterday();
	return before;
}

Date::operator int() const
{

	int days=0;
	for (int i = 1; i <= this->_month-1; i++)
	{
		days +=  Date::getMaxDay(i,this->_year);
	}
	days += this->_day;
	return days;
}

Date::operator long() const
{

	int days = 0;
	for (int i = 1; i <= this->_month - 1; i++)
		days += Date::getMaxDay(i, this->_year);

	for (int i = 1; i <= this->_year -1; i++)
		days += 365 + (int)isLeapYear(i);

	days += this->_day;
	return days;
}

Date& Date::operator+=(const int& num)
{
	
	for (int i = 1; i <= num; i++)
		*this = this->Tomorrow();
	return *this;
}

Date& Date::operator-=(const int& num)
{
	
	for (int i = 1; i <= num; i++)
		*this = this->Yesterday();
	return *this;
}

