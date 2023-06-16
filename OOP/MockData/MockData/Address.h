#pragma once
#include <string>
using namespace std;

class Address {
public:
	Address();
	Address(string, string, string,string);
public:
	string toString();
private:
	string _number;
	string _street;
	string _ward;
	string _district;
	const string _city = "Ho Chi Minh";
	
};