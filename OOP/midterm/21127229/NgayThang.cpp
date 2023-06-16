#include "NgayThang.h"
#include "iostream"
#include "iomanip"

NgayThang::NgayThang()
{
	this->_year = 1;
	this->_month = 1;
	this->_day = 1;
}

NgayThang::NgayThang(int day)
{
	//60/1/1
	this->_year = 1;
	this->_month = 1;
	if (day < 0)
	{
		day = -day;
	}
	if (day == 0) day = 1;
	if (day > getMaxDay(this->_month,this->_year))
	{
		int i = 0;
		while (day > getMaxDay(this->_month + i, this->_year))
		{
			day = day - getMaxDay(this->_month + i, this->_year);
			if (this->_month == 12) 
			{
				this->_year++; this->_month = 1;
				
			}
			else this->_month++;
			i++;
		}
	}
	this->_day = day;

}

NgayThang::NgayThang(int month, int day)
{
	this->_year = 1;
	if (month < 0) month = -month;
	if (month == 0) month = 1;
	if (month > 12)
	{
		this->_year += month / 12;
		month = month % 12;
	}
	
	this->_month = month;
	if (day < 0)
	{
		day = -day;
	}
	if (day == 0) day = 1;
	if (day > getMaxDay(this->_month, this->_year))
	{
		int i = 0;
		while (day > getMaxDay(this->_month + i, this->_year))
		{
			day = day - getMaxDay(this->_month + i, this->_year);
			if (this->_month == 12)
			{
				this->_year++; this->_month = 1;

			}
			else this->_month++;
			i++;
		}
	}
	
	this->_day = day;
}

NgayThang::NgayThang(int year, int month, int day)
{
	if (year < 0) year = -year;
	if (year == 0) year = 1;
	this->_year = year;
	if (month < 0) month = -month;
	if (month == 0) month = 1;
	if (month > 12)
	{
		this->_year += month / 12;
		month = month % 12;
	}
	
	this->_month = month;
	if (day < 0)
	{
		day = -day;
	}
	if (day == 0) day = 1;
	if (day > getMaxDay(this->_month, this->_year))
	{
		int i = 0;
		while (day > getMaxDay(this->_month + i, this->_year))
		{
			day = day - getMaxDay(this->_month + i, this->_year);
			if (this->_month == 12)
			{
				this->_year++; this->_month = 1;

			}
			else this->_month++;
			i++;
		}
	}
	
	this->_day = day;
}

NgayThang::NgayThang(const NgayThang& other)
{
	this->_day = other._day;
	this->_month = other._month;
	this->_year = other._year;
}

NgayThang& NgayThang::operator=(const NgayThang& other)
{

	this->_day = other._day;
	this->_month = other._month;
	this->_year = other._year;
	return *this;
}

bool NgayThang::isLeapYear(int year)
{
	bool result;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		result = true;
	else result = false;
	return result;
}

int NgayThang::getMaxDay(int month, int year)
{
	int maxDay = 31;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		maxDay = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		maxDay = 30;
		break;
	case 2:
		if (isLeapYear(year) == true) maxDay = 29;
		else maxDay = 28;
		break;
	}
	return maxDay;
}

NgayThang NgayThang::Tomorrow()const
{
	NgayThang tomorrow(*this);
	tomorrow._day = this->_day % getMaxDay(this->_month, this->_year) + 1;
	if (tomorrow._day == 1)
		tomorrow._month = (this->_month % 12) + 1;
	if (tomorrow._day == 1 && tomorrow._month == 1) tomorrow._year = this->_year + 1;
	return tomorrow;
}

NgayThang NgayThang::Yesterday()const
{
	NgayThang yesterday(*this);
	if (this->_day == 1)
	{
		yesterday._day = getMaxDay(this->_month - 1, this->_year);
		if (this->_month == 1)
		{
			yesterday._month = 12;
			yesterday._year = this->_year - 1;
		}
		else yesterday._month--;
	}
	else yesterday._day = this->_day - 1;
	return yesterday;
}



ostream& operator<<(ostream& os, const NgayThang& NgayThang)
{
	os << setw(2) << NgayThang._day << "/" << setw(2) << NgayThang._month << "/" << setw(4) << NgayThang._year;
	return os;
}

int NgayThang::getDay()
{
	return this->_day;
}
NgayThang& NgayThang::operator+(const NgayThang& other)
{
	/*int day = this->_day + other._day;
	
	int month = this->_month + other._month;
	int year = this->_year + other._year;
	NgayThang result(year, month, day);*/
	
	
	NgayThang result = other;
	int day = other._day;
	int month = other._month;
	int year = other._year;
	for (int i = year; i >= 1; i--)
	{
		for (int j = month; j >=1; j--)
		{
			for (int k = day; k >=1; k--)
				result = result.Tomorrow();
			day = getMaxDay(j-1, i);
		}
		month = 12;
	}
	return result;
	
}

NgayThang& operator+(const int& num, const NgayThang& date)
{
	NgayThang result = date;
	int day =date._day;
	int month = date._month;
	int year = date._year;
	for (int i = year; i >= 1; i--)
	{
		for (int j = month; j >= 1; j--)
		{
			for (int k = day; k >= 1; k--)
				result = result.Tomorrow();
			day = NgayThang::getMaxDay(j - 1, i);
		}
		month = 12;
	}
	return result;
}
NgayThang& NgayThang::operator++()
{
	*this = this->Tomorrow();
	return *this;
}

NgayThang NgayThang::operator++(int)
{
	NgayThang* NgayThang = this;
	*this = this->Tomorrow();
	return *NgayThang;
}


NgayThang& NgayThang::operator+(const int& num)
{
	NgayThang after=*this;
	for (int i = 1; i <= num; i++)
		after = after.Tomorrow();
	return after;
}




