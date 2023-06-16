#pragma once
#include <fstream>
#include "Product.h"
#include <vector>
class File;

class File:public Object
{
public:
	File(string);
private:
	string _fileName;

public:
	vector<Product> readFile();
	void writeFile(vector<Product>);
	string toString();
};