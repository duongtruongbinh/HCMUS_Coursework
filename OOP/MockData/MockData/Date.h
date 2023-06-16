#pragma once
#include <string>
using namespace std;
class Date {
public:
	Date();	
	Date(int, int, int);
	static Date Now() { return Date(); }
	
public:
	int year() { return _year; }
	int month() { return _month; }
	int day() { return _day; }
	static bool isValidDate(int, int, int);
	static bool isLeapYear(int);
	static int getMaxDay(int, int);
	string toString();
private:
	int _day;
	int _month;
	int _year;
};