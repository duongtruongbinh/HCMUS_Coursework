#include "Table.h"

Table::Table(vector<string> instruction, vector<string> header, vector<int> width, vector<Product>data)
{
	
	this->_instruction = instruction;
	this->_header = header;
	this->_width = width;
	this->_data = data;
}

string Table::toString()
{
	return "Table";
}

vector<Product> Table::data()
{
	return this->_data;
}

vector<int> Table::width()
{
	return this->_width;
}

vector<string> Table::instruction()
{
	return this->_instruction;
}

vector<string> Table::header()
{
	return this->_header;
}

