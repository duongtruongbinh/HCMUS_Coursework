#include "Product.h"

Product::Product()
{
	this->_id = 0;
	this->_cost = 0;
	this->_name = "";
	this->_producer = "";
}

Product::Product(const Product& other)
{
	this->_id = other._id;
	this->_cost = other._cost;
	this->_name = other._name;
	this->_producer = other._producer;
}

double Product::price()
{
	return 1.1 * _cost;
}

void Product::input()
{
	cout << "ID: "; cin >> _id;
	
	cout << "Name: ";
	cin.ignore(); getline(cin, _name);
	
	cout << "Producer: ";
	getline(cin, _producer);
	cout << "Cost: "; cin >> _cost;
}

void Product::output()
{
	cout << "ID: " << this->_id << endl;
	cout << "Name: " << this->_name << endl;
	cout << "Producer: " << this->_producer << endl;
	cout << "Cost: " << this->_cost << endl;
}

string Product::producer()
{
	return _producer;
}

string Product::name()
{
	return _name;
}

int Product::id()
{
	return this->_id;

}

int Product::cost()
{
	return _cost;
}