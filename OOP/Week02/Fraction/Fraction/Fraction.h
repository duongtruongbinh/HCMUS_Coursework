#pragma once

class Fraction {
private:
	int _num;
	int _den;
public:
	Fraction();
	Fraction(int, int);
	Fraction(int);
	Fraction(int, bool);
	Fraction(const Fraction&);

	~Fraction();
public:
	void display();
};
