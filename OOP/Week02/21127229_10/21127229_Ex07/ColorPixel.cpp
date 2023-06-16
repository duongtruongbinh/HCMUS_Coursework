#include <iostream>
#include "ColorPixel.h"
using namespace std;

ColorPixel::ColorPixel()
{
	this->_red = 0;
	this->_blue = 0;
	this->_green = 0;
}

ColorPixel::ColorPixel(int red)
{
	if (isValidColor(red, 0, 0) == false)
		red = 0;
	this->_red = red;
	this->_green = 0;
	this->_blue = 0;
}

ColorPixel::ColorPixel(int red, int green)
{
	if (isValidColor(red, green, 0) == false)
	{
		red = 0; green = 0;
	}
	this->_red = red;
	this->_green = green;
	this->_blue = 0;
}

ColorPixel::ColorPixel(int red, int green,int blue)
{
	if (isValidColor(red, green, blue) == false)
	{
		red = 0; green = 0;blue = 0;
	}
	this->_red = red;
	this->_green = green;
	this->_blue = blue;
}

ColorPixel::ColorPixel(const ColorPixel& other)
{
	this->_red = other._red;
	this->_green = other._green;
	this->_blue = other._blue;
}

ColorPixel& ColorPixel::operator=(const ColorPixel& other)
{
	this->_red = other._red;
	this->_green = other._green;
	this->_blue = other._blue;
	return *this;
}

ColorPixel::~ColorPixel() {
	cout << "An object of class ColorPixel has been removed." << endl;
}

void ColorPixel::display()
{
	cout << "R: " << this->_red << " G: " << this->_green << " B: " << this->_blue << endl;
}

bool ColorPixel::isValidColor(int red, int green, int blue)
{
	bool result = true;
	if (red < 0 || red>255) result = false;
	if (green < 0 || green>255) result = false;
	if (blue < 0 || blue>255) result = false;
	return result;
}