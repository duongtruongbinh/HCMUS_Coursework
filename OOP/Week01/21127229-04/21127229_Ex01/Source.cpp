#include "Header.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int Integer::gcd(int a,int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

void Fraction::input()
{
	int num, den;
	do
	{
		cout << "Num: "; cin >> num;
		cout << "Den: "; cin >> den;
		if (den == 0) cout << "Fraction invalid." << endl;
	} while (den == 0);
	this->_num = num;
	this->_den = den;
}

void Fraction::output()
{
	stringstream builder;
	builder << this->_num << "/" << this->_den;
	string res = builder.str();
	cout << res;
}

Fraction Fraction::add(Fraction value)
{
	Integer temp;
	int gcd = temp.gcd(value._den, this->_den);
	int commonDen = value._den * this->_den / gcd;
	int sum = (this->_num * (commonDen / this->_den)) + (value._num * (commonDen / value._den));
	Fraction a;
	a._num = sum;
	a._den = commonDen;
	return a;
}

Fraction Fraction::subtract(Fraction value)
{
	Integer temp;
	int gcd = temp.gcd(value._den, this->_den);
	int commonDen = value._den * this->_den / gcd;
	int res = (this->_num * (commonDen / this->_den)) - (value._num * (commonDen / value._den));
	Fraction a;
	a._num = res;
	a._den = commonDen;
	return a;
}

Fraction Fraction::multiply(Fraction value)
{
	Fraction a;
	a._num = this->_num * value._num;
	a._den = this->_den * value._den;
	return a;
}

Fraction Fraction::divide(Fraction value)
{
	Fraction a ;
	if (value._num == 0) 
	{ 
		cout << "Can't divided by zero." << endl;
		a._num = 99999;
		a._den = 1;
		return a;
	}
	a._num = this->_num * value._den;
	a._den = this->_den * value._num;
	
	return a;
}

void Fraction::reduce()
{
	Integer temp;
	int gcd = temp.gcd(this->_num, this->_den);
	this->_num /= gcd;
	this->_den /= gcd;
	if (this->_den < 0) 
	{
		this->_den *= -1;
		this->_num *= -1;
	}
}

bool Fraction::isNegative()
{
	if (this->_num > 0 && this->_den < 0) return 1;
		else if (this->_num < 0 && this->_den > 0) return 1;
	return 0;		
}

bool Fraction::isPositive()
{
	if (this->_num > 0 && this->_den > 0) return 1;
	else if (this->_num < 0 && this->_den < 0) return 1;
	return 0;
}

bool Fraction::isZero() 
{
	if (this->_num == 0 && this->_den != 0) return 1;
	return 0;
}

int Fraction::compare(Fraction value)
{
	Integer temp;
	int gcd = temp.gcd(value._den, this->_den);
	int commonDen = value._den * this->_den / gcd;
	int num1, num2;
	num1 = this->_num * (commonDen / this->_den);
	num2 = value._num * (commonDen / value._den);
	if (num1 == num2) return 0;
	if (num1 < num2) return -1;
	return 1;
}