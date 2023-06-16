#include "Menu.h"

#include <iomanip>
#include <sstream>
using namespace std;

Menu::Menu(string title, vector<string> option, vector<string>instruction)
{
	this->_title = title;
	this->_option = option;
	this->_instruction = instruction;
}

string Menu::toString()
{
	stringstream builder;
	builder << this->_title << endl;
	for (int i = 0; i < this->_option.size(); i++)
		builder << setw(4) << i << ". " << this->_option[i] << endl;
	
	for (int i = 0; i < this->_instruction.size(); i++)
		builder << _instruction[i] << endl;
	return builder.str();
}

string Menu::title()
{
	return this->_title;
}

vector<string> Menu::option()
{
	return this->_option;
}

vector<string> Menu::instruction()
{
	return this->_instruction;
}
