#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	Date();
	Date(int);
	Date(int, int);
	Date(int, int, int);
	Date(const Date&);
	Date& operator=(const Date&);
public:
	bool operator==(const Date&);
	bool operator!=(const Date&);
	bool operator>=(const Date&);
	bool operator<=(const Date&);
	bool operator>(const Date&);
	bool operator<(const Date&);
	Date operator+(const int&);
	Date operator-(const int&);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	Date& operator+=(const int&);
	Date& operator-=(const int&);
	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream&,  Date&);
	operator int();
	operator long();
public:
	bool isLeapYear(int)const;
	int getMaxDay(int, int)const;
	Date Tomorrow();
	Date Yesterday();
private:
	int _day;
	int _month;
	int _year;
};