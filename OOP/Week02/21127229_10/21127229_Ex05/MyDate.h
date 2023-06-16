#pragma once

class MyDate {
public:
	MyDate();
	MyDate(int);
	MyDate(int, int);
	MyDate(int, int, int);
	MyDate(const MyDate& other);
	MyDate& operator=(const MyDate& other);
	~MyDate();
public:
	bool isValidDate(int, int, int);
	bool isLeapYear(int);
	int getMaxDay(int,int);
	void display();
private:
	int _day;
	int _month;
	int _year;
};