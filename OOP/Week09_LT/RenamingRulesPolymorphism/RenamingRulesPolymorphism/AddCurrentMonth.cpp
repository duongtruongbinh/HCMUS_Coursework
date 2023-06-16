#include "AddCurrentMonth.h"
#include <ctime>
#include <sstream>

string AddCurrentMonth::toString()
{
	return "AddCurrentMonth";
}

string AddCurrentMonth::rename(string name)
{
	time_t now = time(0);
	struct tm newtime;
	localtime_s(&newtime,&now);
	stringstream builder;
	builder << 1 + newtime.tm_mon << 1900 + newtime.tm_year - 2000 << " ";
	builder << name;
	return builder.str();
}