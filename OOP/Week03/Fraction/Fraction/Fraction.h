#pragma once
#include <iostream>
using namespace std;

class Fraction;
class Fraction
{
public:
	Fraction();
	Fraction(int, int);
	Fraction& operator=(const Fraction&);
	Fraction(const Fraction&);

public:
	Fraction& operator+(const Fraction&);
	Fraction& operator+(const int&);
	friend Fraction& operator+(const int&, const Fraction&);
	Fraction& operator+=(const Fraction&);

	Fraction& operator-(const Fraction&);
	Fraction& operator-(const int&);
	friend Fraction& operator-(const int&, const Fraction&);
	Fraction& operator-=(const Fraction&);

	Fraction& operator*(const Fraction&);
	Fraction& operator*(const int&);
	friend Fraction& operator*(const int&, const Fraction&);
	Fraction& operator*=(const Fraction&);

	Fraction& operator/(const Fraction&);
	Fraction& operator/(const int&);
	friend Fraction& operator/(const int&, const Fraction&);
	Fraction& operator/=(const Fraction&);

	bool operator==(const Fraction&);
	bool operator!=(const Fraction&);
	bool operator>=(const Fraction&);
	bool operator>(const Fraction&);
	bool operator<=(const Fraction&);
	bool operator<(const Fraction&);
	friend ostream& operator<<(ostream&, const Fraction&);
	
	Fraction& operator ++();
	Fraction operator ++(int);
	Fraction& operator --();
	Fraction operator --(int);
	operator float() const;
public:
	void display();
private:
	int _num;
	int _den;

};