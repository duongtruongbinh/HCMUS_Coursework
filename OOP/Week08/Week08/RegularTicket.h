#pragma once
#include "Ticket.h"

class RegularTicket;

class RegularTicket:public Ticket
{
public:
	RegularTicket(string, Time, string, int);

public:
	int price();
	void toString();
	int type();
private:
	double _ticketFactor = 1.5;

};