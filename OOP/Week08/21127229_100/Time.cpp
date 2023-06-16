#include "Time.h"
#include <iostream>
#include <iomanip>
using namespace std;


Time::Time(int hour, int minute)
{
	this->_hour = hour;
	this->_minute = minute;
}

Time::Time(const Time& other)
{
	this->_hour = other._hour;
	this->_minute = other._minute;
}

Time::Time()
{
	this->_hour = 0;
	this->_minute = 0;
}

void Time::toString()
{
	
	cout << setfill('0');
	cout << setw(2) << this->_hour << ":" << setw(2) << this->_minute << endl;
	cout << setfill(' ');
}

int Time::hour()
{
	return _hour;
}