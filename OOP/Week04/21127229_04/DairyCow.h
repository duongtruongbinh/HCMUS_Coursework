#pragma once
#include <iostream>
#include <string>
#include "Animal.h"
using namespace std;

class DairyCow: public Animal
{
public:
	DairyCow();
	DairyCow( double, double);
	DairyCow(const DairyCow&);
	
	~DairyCow();

public:
	void ToString();


};