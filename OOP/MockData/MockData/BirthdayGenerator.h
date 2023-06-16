#pragma once
#include "Date.h"
#include "RandomIntegerGenerator.h"

class BirthdayGenerator
{
public:
	Date next();
	Date next(int);
};