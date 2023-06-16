#pragma once
#include "IValueConverter.h"

class IntegerToCurrencyConverter;

class IntegerToCurrencyConverter :public IValueConverter
{public:
	string convert(int);
};