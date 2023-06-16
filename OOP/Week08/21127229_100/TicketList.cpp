#include "TicketList.h"
#include <iomanip>
void TicketList::input()
{
	
	cout << "Nhap so luong ve: ";
	int numberTicket; cin >> numberTicket;
	for (int i = 0; i < numberTicket; i++)
	{
		cout << "=====================================" << endl;
		cout << "Nhap thong tin cho ve thu " << i + 1 << endl;
		string title,roomName;
		int hour, minute,priceFoodAndDrink,factor;
		getline(cin, title);
		int type; Ticket* ticket;
		cout << "Nhap loai ve: (0 => Regular Ticket || 1 => Combo Ticket)";
		cin >> type;
		getline(cin, title);
		cout << "Input film title: "; getline(cin, title);
		cout << "Input start time." << endl;
		cout << "Input hour: "; cin >> hour;
		cout << "Input minute: "; cin >> minute;
		Time time(hour, minute);
		getline(cin, roomName);
		cout << "Input room name: "; getline(cin, roomName);
		cout << "Input price of food and drink: "; cin >> priceFoodAndDrink;

		if (type == 0) ticket = new RegularTicket(title, time, roomName, priceFoodAndDrink);
		else ticket = new ComboTicket(title, time, roomName, priceFoodAndDrink);
		_list.push_back(ticket);
	}
}

void TicketList::output()
{
	for (int i = 0; i < this->_list.size(); i++)
	{
		cout << "======================" << endl;
		cout << "Thong tin ve thu " << i << endl;
		_list[i]->toString();
	}
}

void TicketList::sort()
{
	for (int i = 0; i < _list.size() - 1; i++)
		for (int j = i + 1; j < _list.size(); j++)
			if (_list[i]->type() > _list[j]->type())
				swap(_list[i], _list[j]);
			else if (_list[i]->type() == _list[j]->type() && _list[i]->price() < _list[j]->price())
				swap(_list[i], _list[j]);
}

TicketList::~TicketList()
{
	for (int i = 0; i < this->_list.size(); i++)
	{
		delete _list[i];
	}
	_list.clear();
}

TicketList::TicketList()
{

}


void TicketList::summary()
{
	cout << setfill('=') << setw(30) << "SUMMARY" << setw(30) << "=" << endl << setfill(' ');
	cout << setw(15) << "Range" << setw(15) << "#Regular" << setw(15) << "#Combo"<<endl;
	int count[24][2]{ 0 };
	for (int i = 0; i < _list.size(); i++)
	{
		if (_list[i]->type() == 1) count[_list[i]->hour()][_list[i]->type() - 1]++;
		if (_list[i]->type() == 2) count[_list[i]->hour()][_list[i]->type() - 1]++;
	}
	for (int i = 0; i <= 23; i++)
	{
		cout << setw(15) << i;
		
		
		cout << setw(15) << count[i][0] << setw(15) << count[i][1] << endl;
	}
}