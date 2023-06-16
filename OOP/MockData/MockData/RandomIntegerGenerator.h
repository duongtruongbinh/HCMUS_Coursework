#pragma once
#include <memory>
using namespace std;

class RandomIntegerGenerator {
public:
	static shared_ptr<RandomIntegerGenerator> instance();
	int next();
	int next(int, int);

private:
	RandomIntegerGenerator() { srand(time(nullptr)); }
	inline static shared_ptr<RandomIntegerGenerator> _instance = nullptr;
};