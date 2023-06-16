#include "Point2D.h"
#include <iostream>
#include <sstream>
using namespace std;

Point2D::Point2D() {
	this->_x = 0;
	this->_y = 0;
}

Point2D::Point2D(double value)
{
	this->_x = value;
	this->_y = 0;
}

Point2D::Point2D(double x, double y)
{
	this->_x = x;
	this->_y = y;
}

/// <summary>
/// 
/// </summary>
/// <param name="value"></param>
/// <param name="check">if check==1 x=value ,else y=value</param>
Point2D::Point2D(double value, bool check)
{
	if (check == 1)
	{
		this->_x = value;
		this->_y = 0;
	}
	else
	{
		this->_y = value;
		this->_x = 0;
	}
}

Point2D::Point2D(const Point2D& other)
{
	this->_x = other._x;
	this->_y = other._y;
}

Point2D::~Point2D()
{
	cout << "An object of class Point2D has been removed." << endl;
}

void Point2D::display() {
	stringstream builder;
	builder << "(" << this->_x << "," << this->_y << ")" << endl;
	cout << builder.str();
}
