#include "MyTime.h"
#include <iostream>
using namespace std;

MyTime::MyTime()
{
	this->_second = 0;
	this->_minute = 0;
	this->_hour = 0;
}

MyTime::MyTime(int hour) 
{
	if (isValidTime(0, 0, hour) == false)
		hour = 0;
	this->_second = 0;
	this->_minute = 0;
	this->_hour = hour;
}

MyTime::MyTime(int hour,int minute)
{
	if (isValidTime(0, minute, hour) == false)
	{
		hour = 0;
		minute = 0;
	}
	this->_second = 0;
	this->_minute = minute;
	this->_hour = hour;
}

MyTime::MyTime(int hour, int minute,int second)
{
	if (isValidTime(second, minute, hour) == false)
	{
		hour = 0;
		minute = 0;
		second = 0;
	}
	this->_second = second;
	this->_minute = minute;
	this->_hour = hour;
}

bool MyTime::isValidTime(int second, int minute, int hour)
{
	bool result = true;
	if (hour > 23 || hour < 0) result = false;
	if (minute > 59 || minute < 0) result = false;
	if (second > 59 || second < 0) result = false;
	return result;
}

MyTime::MyTime(const MyTime& other)
{
	this->_hour = other._hour;
	this->_minute = other._minute;
	this->_second = other._second;
}

MyTime& MyTime::operator=(const MyTime& other)
{
	this->_hour = other._hour;
	this->_minute = other._minute;
	this->_second = other._second;
	return *this;
}

MyTime::~MyTime()
{
	cout << "An object of class MyTime has been removed.";
}

void MyTime::display()
{
	cout << this->_hour << ":" << this->_minute << ":" << this->_second << endl;
}

