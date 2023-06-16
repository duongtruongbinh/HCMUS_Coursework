#pragma once
#include "Object.h"
class NumberFormatInfo : public Object {
private:
	string _currencyDecimalSeparator = ".";
	string _currencySymbol = "d";

	// https://stackoverflow.com/questions/17459450/how-to-determine-currency-symbol-position-for-a-culture
	int _currencyPositive = 3;				// 0		1		2		3
	string _currencyPositiveFormat = "n $"; // "$n"		"n$"	"$ n"	"n $"
public:
	string currencyDecimalSeparator();
	string currencySymbol();
	int currencyPositive();
	string currencyPositiveFormat();
public:
	string toString();
};