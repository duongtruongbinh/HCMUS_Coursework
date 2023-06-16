#include "DailyEmployee.h"

DailyEmployee::DailyEmployee()
{
    this->_day = 0;
    this->_payPerDay = 0;
}

DailyEmployee::DailyEmployee(long day, long pay)
{
    this->_day = day;
    this->_payPerDay = pay;
}

long DailyEmployee::salary()
{
    long result = this->_day * this->_payPerDay;
    return result;
}