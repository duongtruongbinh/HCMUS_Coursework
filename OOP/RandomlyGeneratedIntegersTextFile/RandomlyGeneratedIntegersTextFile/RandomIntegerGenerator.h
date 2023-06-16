#pragma once
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <memory>
using namespace std;

class RandomIntegerGenerator {
public:	
	static shared_ptr<RandomIntegerGenerator> instance()
	{
		if (instance == nullptr)
		{
			auto temp = new RandomIntegerGenerator();
			_instance = shared_ptr<RandomIntegerGenerator>(temp);
		}
		return _instance;
	}
	int next(int,int);
	
private:
	RandomIntegerGenerator() { srand(time(NULL)); }
	inline static shared_ptr<RandomIntegerGenerator> _instance = nullptr;
};