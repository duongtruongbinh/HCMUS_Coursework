#pragma once

class Fraction;
class Integer;

class Fraction {
	int _num;
	int _den;
public:

	void input();
	void output();
	Fraction add(Fraction value);
	Fraction subtract(Fraction value);
	Fraction multiply(Fraction value);
	Fraction divide(Fraction value);
	void reduce();
	int compare(Fraction value);
	bool isPositive();
	bool isNegative();
	bool isZero();
};

class Integer {
public:
	int gcd(int a, int b);
};