#pragma once

class MyTime {
public:
	MyTime();
	MyTime(int);
	MyTime(int, int);
	MyTime(int, int, int);
	MyTime(const MyTime& other);
	MyTime& operator=(const MyTime& other);
	~MyTime();
public:
	bool isValidTime(int, int, int);
	void display();

private:
	int _second;
	int _minute;
	int _hour;	
};