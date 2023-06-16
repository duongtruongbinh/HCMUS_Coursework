#include "ProductEmployeeParser.h"
#include "ProductEmployee.h" 
string ProductEmployeeParser::parsedObjectName()
{
	return "ProductEmployee";
}

Object* ProductEmployeeParser::parse(string parameter)
{
	vector<string> token = Utils::String::split(parameter, ", ");
	int product = stoi(Utils::String::split(token[0], "=")[1]);
	int payPerProduct = stoi(Utils::String::split(token[1], "=")[1]);
	return new ProductEmployee(product,payPerProduct);
}
string ProductEmployeeParser::toString()
{
	return "ProductEmployeeParser";
}