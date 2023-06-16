#pragma once
#include "RegularTicket.h"
#include "ComboTicket.h"
#include <vector>
#include <fstream>
using namespace std;
class TicketList;

class TicketList
{
public:
	void input();
	void output();
	void sort();
	void saveSortedListToTextFile(string);
	void summary();

public:
	TicketList();
	~TicketList();

private:
	vector<Ticket*> _list;

};