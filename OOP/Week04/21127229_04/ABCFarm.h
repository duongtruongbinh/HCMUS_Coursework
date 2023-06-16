#pragma once
#include "DairyCow.h"
#include "Goat.h"
#include <vector>
class ABCFarm {
private:
	vector<DairyCow> cows;
	vector<Goat> goats;

public:
	void Input();
	void Output();
	void OutputByAge(int min, int max);
};