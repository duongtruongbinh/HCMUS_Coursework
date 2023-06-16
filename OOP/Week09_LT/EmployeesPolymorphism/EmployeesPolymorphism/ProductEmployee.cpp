#include "ProductEmployee.h"

string ProductEmployee::toString()
{
	return "Product employee";
}

int ProductEmployee::salary()
{
	return _productCount * _paymentPerProduct;
}

ProductEmployee::ProductEmployee(int product, int pay)
{
	this->_productCount = product;
	this->_paymentPerProduct = pay;
}