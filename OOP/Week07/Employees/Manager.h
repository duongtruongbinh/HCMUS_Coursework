#pragma once
#include "Employee.h"

class Manager;

class Manager
{
public:
    Manager();
    Manager(long, long);

public:
    long salary();

protected:
    long _managedEmployee;
    long _fixedPayPerMonth;
};