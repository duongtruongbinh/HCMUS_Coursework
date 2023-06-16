#include "Fraction.h"
#include <iostream>
using namespace std;

Fraction::Fraction()
{
	this->_num = 0;
	this->_den = 1;
}

Fraction::Fraction(int num, int den)
{
	if (den == 0) { num = 0; den = 1; }
	this->_den = den;
	this->_num = num;
}

Fraction::Fraction(const Fraction& other)
{
	this->_num = other._num;
	this->_den = other._den;
}

Fraction& Fraction::operator=(const Fraction& other)
{
	this->_num = other._num;
	this->_den = other._den;
	return *this;
}

Fraction& Fraction::operator+(const Fraction& other)
{
	Fraction result;
	result._den = this->_den * other._den;
	result._num = this->_num * other._den + other._num * this->_den;
	return result;
}

Fraction& Fraction::operator-(const Fraction& other)
{
	Fraction result;
	result._den = this->_den * other._den;
	result._num = this->_num * other._den - other._num * this->_den;
	return result;
}

Fraction& Fraction::operator*(const Fraction& other)
{
	Fraction result;
	result._den = this->_den * other._den;
	result._num = this->_num * other._num;
	return result;
}

Fraction& Fraction::operator/(const Fraction& other)
{
	Fraction result;
	result._den = this->_den * other._num;
	result._num = this->_num * other._den;
	return result;
}

bool Fraction::operator==(const Fraction& other)
{
	bool result;
	result = this->_num * other._den == this->_den * other._num;
	return result;
}

bool Fraction::operator!=(const Fraction& other)
{
	return !operator==(other);
}

bool Fraction::operator>=(const Fraction& other)
{
	bool result = false;
	int commonDen = this->_den * other._den;
	if (commonDen > 0 && this->_num * other._den >= other._num * this->_den) result = true;
	if (commonDen < 0 && this->_num * other._den <= other._num * this->_den) result = true;
	return result;
}

bool Fraction::operator>(const Fraction& other)
{
	bool result = false;
	int commonDen = this->_den * other._den;
	if (commonDen > 0 && this->_num * other._den > other._num * this->_den) result = true;
	if (commonDen < 0 && this->_num * other._den < other._num * this->_den) result = true;
	return result;
}

bool Fraction::operator<=(const Fraction& other)
{
	bool result = false;
	int commonDen = this->_den * other._den;
	if (commonDen > 0 && this->_num * other._den <= other._num * this->_den) result = true;
	if (commonDen < 0 && this->_num * other._den >= other._num * this->_den) result = true;
	return result;
}

bool Fraction::operator<(const Fraction& other)
{
	bool result = false;
	int commonDen = this->_den * other._den;
	if (commonDen > 0 && this->_num * other._den < other._num * this->_den) result = true;
	if (commonDen < 0 && this->_num * other._den > other._num * this->_den) result = true;
	return result;
}

void Fraction::display()
{
	cout << this->_num << "/" << this->_den << endl;
}

Fraction& Fraction::operator+(const int& number)
{
	Fraction result;
	result._den = this->_den;
	result._num = this->_num + number * this->_den;
	return result;
}

Fraction& Fraction::operator-(const int& number)
{
	Fraction result;
	result._den = this->_den;
	result._num = this->_num - number * this->_den;
	return result;
}

Fraction& Fraction::operator*(const int& number)
{
	Fraction result;
	result._den = this->_den;
	result._num = this->_num * number ;
	return result;
}

Fraction& Fraction::operator/(const int& number)
{
	Fraction result;
	result._den = this->_den * number;
	result._num = this->_num ;
	return result;
}

Fraction& operator+(const int& number, const Fraction& other)
{
	Fraction result;
	result._den = other._den;
	result._num = other._num + number * other._den;
	return result;
}

Fraction& operator-(const int& number, const Fraction& other)
{
	Fraction result;
	result._den = other._den;
	result._num = other._num - number * other._den;
	return result;
}

Fraction& operator*(const int& number, const Fraction& other)
{
	Fraction result;
	result._den = other._den;
	result._num = other._num + number;
	return result;
}

Fraction& operator/(const int& number, const Fraction& other)
{
	Fraction result;
	result._den = other._den * number;
	result._num = other._num ;
	return result;
}

ostream& operator<<(ostream& os, const Fraction& f)
{
	os << f._num << "/" << f._den;
	return os;
}

Fraction& Fraction::operator+=(const Fraction& other)
{
	int commonDen= this->_den * other._den;
	
	this->_num = this->_num * other._den + other._num * this->_den;
	this->_den = commonDen;
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& other)
{
	int commonDen = this->_den * other._den;

	this->_num = this->_num * other._den - other._num * this->_den;
	this->_den = commonDen;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	
	this->_den = this->_den * other._den;
	this->_num = this->_num * other._num;
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& other)
{

	this->_den = this->_den * other._num;
	this->_num = this->_num * other._den;
	return *this;
}

Fraction& Fraction::operator++()
{
	this->_num += this->_den;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction f = *this;
	this->_num += this->_den;
	return f;
}

Fraction& Fraction::operator--()
{
	this->_num -= this->_den;
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction f = *this;
	this->_num -= this->_den;
	return f;
}

Fraction::operator float()const {
	return float(this->_num) / float(this->_den);
}
