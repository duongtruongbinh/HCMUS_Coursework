#pragma once
#include <vector>
#include "Worker.h"
#include "OfficeEmployee.h"

class Company;

class Company {
protected:
	vector<Employee*> array;
public:
	void input();
	void output();
	void outputSalary();
	void outputBiggestSalary();

public:
	~Company();
};