#include "RandomIntegerGenerator.h"


int RandomIntegerGenerator::next(int left, int right)
{
	int number = rand() % (right - left + 1) + left;
	return number;
}

int RandomIntegerGenerator::next()
{
	int number = rand();
	return number;
}

shared_ptr<RandomIntegerGenerator> RandomIntegerGenerator::instance()
{
	if (_instance == nullptr)
	{
		RandomIntegerGenerator* temp = new RandomIntegerGenerator();
		_instance = shared_ptr<RandomIntegerGenerator>(temp);
	}
	return _instance;
}