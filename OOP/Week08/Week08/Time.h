#pragma once

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

private:
	int _hour;
	int _minute;
};