#pragma once
#include "Employee.h"

class ProductEmployee;

class ProductEmployee : public Employee
{
public:
	ProductEmployee(int, int);
	string toString();
	int salary();
private:
	int _productCount;
	int _paymentPerProduct;
};