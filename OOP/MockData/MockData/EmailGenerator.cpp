#include "EmailGenerator.h"
#include "VnFullnameGenerator.h"
#include "File.h"
#include <sstream>
#include <algorithm>
string EmailGenerator::next(FullName name)
{
	stringstream builder;
	stringstream temp;
	VnFullnameGenerator nameGen;
	string emailName = name.toString();
	
	transform(emailName.begin(), emailName.end(), emailName.begin(), ::tolower);

	temp << emailName;
	string first, middle, last;
	temp >> first >> middle >> last;
	builder << first[0] << middle[0] << last;

	File file;
	string company = file.readFile("domain.txt");
	auto generator = RandomIntegerGenerator::instance();
	builder << company << ".com";
	return builder.str();
}