#include "ComboTicket.h"

ComboTicket::ComboTicket(string title, Time time, string roomName, int priceFoodAndDrink) :Ticket(title, time, roomName, priceFoodAndDrink)
{

}

int ComboTicket::type()
{
	return 2;
}

int ComboTicket::price()
{
	int price = _ticketFactor * _basePrice + _priceFoodAndDrink * 0.8;
	return price;
}
void ComboTicket::toString()
{
	cout << "Combo Ticket" << endl;
	cout << "Film title: "<<_filmTitle << endl;
	cout << "Start time: "; _startTime.toString();
	cout << "Room name: " << _roomName << endl;
	cout << "Price of food and drink: " << _priceFoodAndDrink << endl;
	cout << "Ticket factor: " << _ticketFactor << endl;


}