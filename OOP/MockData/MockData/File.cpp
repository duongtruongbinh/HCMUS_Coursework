#include "File.h"
#include "AddressGenerator.h"
#include "BirthdayGenerator.h"
#include "EmailGenerator.h"
#include "TelGenerator.h"
#include "VnFullnameGenerator.h"
#include "GPAGenerator.h"
#include "IDGenerator.h"
#include <iomanip>


string File::readFile(string fileName)
{
	ifstream file(fileName, ios::in);
	vector<string> array;
	while (!file.eof())
	{
		string reader;
		getline(file, reader);
		array.push_back(reader);
	}
	auto generator = RandomIntegerGenerator::instance();
	string result = array[generator->next(1, array.size() - 1)];
	file.close();
	return result;
}

void File::writeFile(string fileName)
{
	ofstream file(fileName, ios::out);
	IDGenerator idGen;
	VnFullnameGenerator nameGen;
	TelGenerator telGen;
	BirthdayGenerator birthGen;
	EmailGenerator emailGen;
	AddressGenerator addressGen;
	GPAGenerator gpaGen;

	for (int i = 1; i <= 30; i++)
	{
		int id = idGen.next();
		FullName name = nameGen.next();
		string tel = telGen.next();
		Date birth = birthGen.next();
		string email = emailGen.next(name);
		Address address = addressGen.next();
		string gpa = gpaGen.next();

		file << setw(10) << left << id << setw(20) << left << name.toString() << setw(20) << tel << setw(15) << birth.toString() << " " << setw(25) << email << setw(80) << address.toString() << setw(5) << right << gpa;
		if (i < 30) file << endl;
	}
	file.close();
}