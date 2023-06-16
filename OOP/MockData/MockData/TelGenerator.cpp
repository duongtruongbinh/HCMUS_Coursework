#include "TelGenerator.h"
#include <sstream>

string TelGenerator::next()
{
	auto generator = RandomIntegerGenerator::instance();
	stringstream builder;
	builder << 0;
	int number = generator->next(80, 99);
	builder << number;
	for (int i = 1; i <= 9; i++)
	{
		if (i == 2 || i == 6)
		{
			builder << " ";
			continue;
		}
		number = generator->next(0, 9);
		builder << number;
	}
	return builder.str();
}