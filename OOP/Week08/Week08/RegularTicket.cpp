#include "RegularTicket.h"


RegularTicket::RegularTicket(string title,Time time,string roomName,int priceFoodAndDrink):Ticket(title,time,roomName,priceFoodAndDrink)	
{
	
}

int RegularTicket::type()
{
	return 1;
}

int RegularTicket::price()
{
	int price = this->_ticketFactor * _basePrice + _priceFoodAndDrink;
	return price;
}

void RegularTicket::toString()
{
	cout << "Regular Ticket" << endl;
	cout << "Film title: " << _filmTitle << endl;
	cout << "Start time: "; _startTime.toString();
	cout << "Room name: " << _roomName << endl;
	cout << "Price of food and drink: " << _priceFoodAndDrink << endl;
	cout << "Ticket factor: " << _ticketFactor << endl;


}