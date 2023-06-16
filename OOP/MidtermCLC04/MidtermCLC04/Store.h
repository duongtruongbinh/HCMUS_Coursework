#pragma once
#include "Product.h"
#include <vector>
#include <fstream>
using namespace std;

class Store;

class Store
{
public:
	Store();
public:
	void input();
	void output();
	void outputProductFromProducer(string);
	void sort();
	double totalPrice();
private:
	vector<Product> _list;
	
};