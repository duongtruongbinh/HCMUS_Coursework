#pragma once
#include "Employee.h"

class DailyEmployee;

class DailyEmployee : public Employee
{
public:
    DailyEmployee();
    DailyEmployee(long, long);

public:
    long salary();

protected:
    long _day;
    long _payPerDay;
};