#pragma once
#include <string>
#include "Time.h"
#include <iostream>
using namespace std;
class Ticket;

class Ticket
{public:
	Ticket(string, Time, string, int);

public:
	int hour();

public:
	virtual int price() = 0;
	virtual void toString() = 0;
	virtual int type() = 0;
	
protected:
	string _filmTitle;
	Time _startTime;
	string _roomName;
	int _priceFoodAndDrink;
	int _basePrice = 80000;
};