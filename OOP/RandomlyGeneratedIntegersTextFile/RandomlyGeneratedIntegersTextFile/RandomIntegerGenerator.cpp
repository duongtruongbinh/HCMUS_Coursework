#include "RandomIntegerGenerator.h"

int RandomIntegerGenerator::next(int left, int right)
{
	int number = rand() % (right - left + 1) + left;
	return number;
}