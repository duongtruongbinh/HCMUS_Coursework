#include "BirthdayGenerator.h"
#include <sstream>

Date BirthdayGenerator::next()
{
	const int MAX_AGE = 118;
	auto generator = RandomIntegerGenerator::instance();
	stringstream builder;
	int currentYear = Date::Now().year();
	int day, month;
	int year;
	do {
		day = generator->next(1, 31);
		month = generator->next(1, 12);
		year = generator->next(currentYear - MAX_AGE, currentYear);
	} while (Date::isValidDate(day, month, year) == false);

	Date birth(day, month, year);
	return birth;
}

Date BirthdayGenerator::next(int year)
{
	const int MAX_AGE = 118;
	auto generator = RandomIntegerGenerator::instance();
	stringstream builder;
	int currentYear = Date::Now().year();
	int day, month;
	
	do {
		day = generator->next(1, 31);
		month = generator->next(1, 12);
		
	} while (Date::isValidDate(day, month, year) == false);

	Date birth(day, month, year);
	return birth;
}

