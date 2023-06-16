#include "TicketList.h"

int main() {
	TicketList list;
	list.input();
	list.output();
	list.saveSortedListToTextFile("text.txt");
	list.summary();
}