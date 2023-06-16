#include "GPAGenerator.h"
#include <sstream>

string GPAGenerator::next()
{
	stringstream builder;
	auto generator = RandomIntegerGenerator::instance();
	builder << generator->next(0, 9) << "." << generator->next(0, 9);
	return builder.str();
}