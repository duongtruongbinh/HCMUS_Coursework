#pragma once
#include "RandomIntegerGenerator.h"
#include "Address.h"

class AddressGenerator
{
public:
	string	HouseNumberGenerate();
	Address next();
};