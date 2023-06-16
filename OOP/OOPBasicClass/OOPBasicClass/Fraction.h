#pragma once
#include <string>
using namespace std;

class Fraction {
private:
    int _num;
    int _den; 
public:
    int numerator() const { return _num; }
    int denominator() const { return _den; }
    void setNumerator(int value)  { _num = value; }
    void setDenominator(int value) { _den = value; }
public:
    Fraction();
    Fraction(int num, int den);
    string toString()const; //converter
};