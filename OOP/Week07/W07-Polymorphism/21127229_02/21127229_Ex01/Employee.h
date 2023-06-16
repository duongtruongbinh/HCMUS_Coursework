#pragma once
#include <string>
#include "Date.h"
using namespace std;

class Employee;

class Employee {
protected:
	int _id;
	string _fullName;
	Date _hireDate;
	string _address;
public:
	Employee();
	Employee(int);
	Employee(int, string);
	Employee(int, string,Date);
	Employee(int, string, Date, string);

public:
	virtual int salary() = 0;
	virtual void input();
	virtual void output();

};
