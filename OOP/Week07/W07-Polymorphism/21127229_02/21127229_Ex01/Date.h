#pragma once


#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	Date();
	Date(int, int, int);
	Date(const Date&);
	Date& operator=(const Date&);
	string toString();

private:
	int _day;
	int _month;
	int _year;
};