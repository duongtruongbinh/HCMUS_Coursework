#include "VnFullnameGenerator.h"
#include "File.h"
#include "Fullname.h"
FullName VnFullnameGenerator::next()
{
	string lastName = File::readFile("lastname.txt");
	string middleName = File::readFile("middlename.txt");
	string firstName = File::readFile("firstname.txt");

	FullName name(firstName, middleName, lastName);
	return name;
}