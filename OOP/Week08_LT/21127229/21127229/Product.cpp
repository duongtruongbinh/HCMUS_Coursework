#include "Product.h"

Product::Product(int id,string name,int price)
{
	this->_id = id;
	this->_name = name;
	this->_price = price;
}

int Product::id()
{
	return this->_id;
}

string Product::name()
{
	return this->_name;
}

int Product::price()
{
	return this->_price;
}

string Product::toString()
{
	string str = "Product";
	return str;
}

Product& Product::operator=(const Product& other)
{
	this->_id = other._id;
	this->_name = other._name;
	this->_price = other._price;
	return *this;
}