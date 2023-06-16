#pragma once
#include "RegularTicket.h"
#include "ComboTicket.h"
#include <vector>

using namespace std;
class TicketList;

class TicketList
{
public:
	void input();
	void output();
	void sort();
	void summary();

public:
	TicketList();
	~TicketList();

private:
	vector<Ticket*> _list;

};