#include "DailyEmployeeParser.h"
#include "DailyEmployee.h"
string DailyEmployeeParser::parsedObjectName()
{
	return "DailyEmployee";
}

Object* DailyEmployeeParser::parse(string parameter)
{
	vector<string> token = Utils::String::split(parameter, ", ");
	int day = stoi(Utils::String::split(token[0], "=")[1]);
	int payPerDay = stoi(Utils::String::split(token[1], "=")[1]);
	return new DailyEmployee(day, payPerDay);
}

string DailyEmployeeParser::toString()
{
	return "DailyEmployeeParser";
}