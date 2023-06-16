#include "Date.h"
#include <ctime>
#include <sstream>


Date::Date()
{
	this->_day = 1;
	this->_month = 1;
	this->_year = 1;
}
Date::Date(int day, int month, int year)
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

string Date::toString()
{
	stringstream builder;
	builder << this->_day << "/" << this->_month << "/" << this->_year;
	return builder.str();
}

