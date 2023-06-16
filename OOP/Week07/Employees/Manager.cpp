#include "Manager.h"

Manager::Manager()
{
    this->_managedEmployee = 0;
    this->_fixedPayPerMonth = 0;
}

Manager::Manager(long employee, long pay)
{
    this->_managedEmployee = employee;
    this->_fixedPayPerMonth = pay;
}

long Manager::salary()
{
    long result = 500000 * this->_managedEmployee + this->_fixedPayPerMonth;
    return result;
}