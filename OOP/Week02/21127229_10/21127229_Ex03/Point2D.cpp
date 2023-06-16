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

Point2D& Point2D::operator=(const Point2D& other)
{
	this->_x = other._x;
	this->_y = other._y;
	return *this;
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

/// <summary>
/// Distance to Point value
/// </summary>
/// <param name="value"></param>
/// <returns>Distance from this point to value point</returns>
double Point2D::distanceTo(Point2D value)
{
	double distance;
	distance = sqrt((this->_x - value._x) * (this->_x - value._x) + (this->_y - value._y) * (this->_y - value._y));
	return distance;
}
