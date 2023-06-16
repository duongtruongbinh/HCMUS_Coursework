#pragma once
#include "Employee.h"

class ProductEmployee;

class ProductEmployee : public Employee
{
public:
    ProductEmployee();
    ProductEmployee(long, long);

public:
    long salary();

protected:
    long _product;
    long _payPerProduct;
};