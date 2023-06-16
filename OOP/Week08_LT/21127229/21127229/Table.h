#pragma once
#include "Object.h"
#include "Product.h"
#include <vector>
#include <string>

using namespace std;

class Table;

class Table :public Object
{
public:
	Table(vector<string>, vector<string>, vector<int>, vector<Product>);
	string toString();
public:
	vector<Product> data();
	vector<int> width();
	vector<string> instruction();
	vector<string> header();
private:
	vector<Product> _data;
	vector<string> _header;
	vector<int> _width;
	
	vector<string> _instruction;
};