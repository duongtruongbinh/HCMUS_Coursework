#pragma once
#include <fstream>
class Time;

class Time
{
public:
	Time();
	Time(int, int);
	Time(const Time&);

public:
	void toString();
	int hour();
	int minute();
	

private:
	int _hour;
	int _minute;
};