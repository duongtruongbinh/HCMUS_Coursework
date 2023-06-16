#pragma once
#include "Console.h"
#include "Table.h"
class DisplayProductConsole;

class DisplayProductConsole : public Console
{private:
	int _numberProductPerPage = 10;
public:
	int display(Table&,int&);
};