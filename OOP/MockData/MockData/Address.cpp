#include "Address.h"
#include <sstream>
#include <string>
using namespace std;

Address::Address()
{
	this->_number = 1;
	this->_district = 1;
	this->_ward = 1;
	this->_street = "";
}

Address::Address(string number, string street, string ward, string district)
{
	this->_number = number;
	this->_ward = ward;
	this->_district = district;
	this->_street = street;
}

string Address::toString()
{
	stringstream builder;
	builder << this->_number << " " << this->_street << " Phuong ";
	builder << this->_ward << " " << this->_district << " Thanh pho " << this->_city;
	return builder.str();

}
