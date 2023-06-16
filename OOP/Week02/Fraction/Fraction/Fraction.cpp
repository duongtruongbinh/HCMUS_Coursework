#include "Fraction.h"
#include <iostream>
#include <sstream>

using namespace std;

Fraction::Fraction()
{
	this->_num = 0;
	this->_den = 1;
}

Fraction::Fraction(int value)
{
	this->_num = value;
	this->_den = 1;
}

Fraction::Fraction(int num, int den)
{
	if (den == 0) {
		this->_num = 0;
		this->_den = 1;
		return;
	}
	else {
		this->_den = den;
		this->_num = num;
	}
}

Fraction::Fraction(int value, bool check)
{
	if (check == 1) {
		this->_num = value;
		this->_den = 1;
	}
	else {
		if (value == 0)
		{
			this->_num = 0;
			this->_den = 1;
		}
		else 
		{
			this->_num = 1;
			this->_den = value;
		}
	}
}

Fraction::Fraction(const Fraction& other)
{
	this->_num = other._num;
	this->_den = other._den;
}

Fraction::~Fraction()
{
	cout << "An object of class Fraction has been removed." << endl;
}

void Fraction::display()
{
	stringstream builder;
	builder << this->_num << "/" << this->_den << endl;
	cout << builder.str();
}


