#pragma once
#include <iostream>
using namespace std;
class NgayThang
{
public:
	int getDay();
	NgayThang();
	NgayThang(int);
	NgayThang(int, int);
	NgayThang(int, int, int);
	NgayThang(const NgayThang&);
	NgayThang& operator=(const NgayThang&);
public:
	
	NgayThang& operator+(const int&);
	NgayThang& operator+(const NgayThang&);
	friend NgayThang& operator+(const int&, const NgayThang&);
	
	NgayThang& operator++();
	NgayThang operator++(int);
	
	friend ostream& operator<<(ostream&, const NgayThang&);


public:
	static bool isLeapYear(int);
	static int getMaxDay(int, int);
	NgayThang Tomorrow()const;
	NgayThang Yesterday()const;
private:
	int _day;
	int _month;
	int _year;
};
