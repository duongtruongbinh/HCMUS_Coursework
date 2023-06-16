#pragma once
#include <string>
using namespace std;

class FullName {
public:
	FullName();
	FullName(string, string, string);
public:
	string first() { return _firstName; }
	string middle() { return _middleName; }
	string last() { return _lastName; }
	string toString();
private:
	string _firstName;
	string _middleName;
	string _lastName;
};
