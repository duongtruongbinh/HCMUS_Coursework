#include "NumberFormatInfo.h"

string NumberFormatInfo::currencyDecimalSeparator()
{
	return this->_currencyDecimalSeparator;
}

string NumberFormatInfo::currencySymbol()
{
	return _currencySymbol;
}

int NumberFormatInfo::currencyPositive()
{
	return _currencyPositive;
}

string NumberFormatInfo::currencyPositiveFormat()
{
	return _currencyPositiveFormat;
}

string NumberFormatInfo::toString()
{
	return "NumberFormatInfo";
}