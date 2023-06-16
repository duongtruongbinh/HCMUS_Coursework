#pragma once
#include <iostream>
#include <string>
#include "Animal.h"
using namespace std;

class Goat : public Animal
{
public:
	Goat();
	Goat(double, double);
	Goat(const Goat&);

	~Goat();

public:
	void ToString();

};