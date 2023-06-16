#include "AddressGenerator.h"
#include "File.h"
#include <sstream>

string AddressGenerator::HouseNumberGenerate()
{
	auto generator = RandomIntegerGenerator::instance();
	stringstream builder;
	builder << generator->next(0, 999);
	int number = generator->next(0, 1);

	if (number == 0) return builder.str();

	builder << "/" << generator->next(0, 999);
	return builder.str();
}

Address AddressGenerator::next()
{
	string houseNumber = HouseNumberGenerate();
	auto generator = RandomIntegerGenerator::instance();

	File file;
	string street = file.readFile("street.txt");

	stringstream builder;
	int temp= generator->next(0,1 );
	if (temp == 1) builder << temp;
	builder << generator->next(0, 9);
	string ward = builder.str();
	string district = file.readFile("district.txt");
	Address address(houseNumber, street, ward, district);
	return address;
}
