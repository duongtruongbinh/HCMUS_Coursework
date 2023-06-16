#pragma once
#include "Ticket.h"

class ComboTicket;

class ComboTicket :public Ticket
{
public:
	ComboTicket(string,Time,string,int);

public:
	int price();
	void toString();
	int type();
private:
	double _ticketFactor = 1;
	
};
