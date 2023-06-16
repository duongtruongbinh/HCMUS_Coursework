#include "IDGenerator.h"
#include "Major.h"
#include <sstream>
#include "RandomIntegerGenerator.h"
using namespace std;
int IDGenerator::next()
{
	stringstream builder;
	auto numGen = RandomIntegerGenerator::instance();
	builder << numGen->next(18, 22) << numGen->next(IT, Physics) << numGen->next(1000, 9999);
	return stoi(builder.str());
}