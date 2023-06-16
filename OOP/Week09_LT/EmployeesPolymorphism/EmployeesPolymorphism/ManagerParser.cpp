#include "ManagerParser.h"
#include "Manager.h"
string ManagerParser::parsedObjectName()
{
	return "Manager";
}

Object* ManagerParser::parse(string parameter)
{
	vector<string> token = Utils::String::split(parameter, ", ");
	int employee = stoi(Utils::String::split(token[0], "=")[1]);
	int payPerEmployee = stoi(Utils::String::split(token[1], "=")[1]);
	int base = stoi(Utils::String::split(token[2], "=")[1]);
	return new Manager(employee,payPerEmployee,base);
}

string ManagerParser::toString()
{
	return "ManagerParser";
}