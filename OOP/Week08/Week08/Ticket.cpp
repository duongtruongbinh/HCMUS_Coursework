#include "Ticket.h"

Ticket::Ticket(string filmTitle, Time startTime, string roomName, int priceFoodAndDrink)
{
	this->_filmTitle = filmTitle;
	this->_startTime = startTime;
	this->_roomName = roomName;
	this->_priceFoodAndDrink = priceFoodAndDrink;
	
}

int Ticket::hour()
{
	return this->_startTime.hour();
}