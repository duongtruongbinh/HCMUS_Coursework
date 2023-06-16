#include "ProductEmployee.h"

ProductEmployee::ProductEmployee()
{
    this->_product = 0;
    this->_payPerProduct = 0;
}

ProductEmployee::ProductEmployee(long product, long pay)
{
    this->_product = product;
    this->_payPerProduct = pay;
}

long ProductEmployee::salary()
{
    long result = this->_product * this->_payPerProduct;
    return result;
}