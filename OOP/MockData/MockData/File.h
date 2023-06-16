#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "RandomIntegerGenerator.h"

using namespace std;
class File {
public:
	static string readFile(string fileName);
	static void writeFile(string);
};