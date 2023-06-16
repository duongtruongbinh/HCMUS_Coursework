#include "Circle.h"
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

Circle::Circle()
{
	this->_center = Point2D(0.0,0.0);
	this->_radius = 1.0;
}

Circle::Circle(Point2D center)
{
	this->_center = center;
	this->_radius = 1.0;
}

Circle::Circle(double radius)
{
	this->_center = Point2D(0.0, 0.0);
	if (radius < 0) radius = 1;
	this->_radius = radius;
}

Circle::Circle(Point2D center, double radius)
{
	if (radius < 0) radius = 1;
	this->_center = center;
	this->_radius = radius;
}

Circle::Circle(const Circle& other) 
{
	this->_center = other._center;
	this->_radius = other._radius;
}

Circle& Circle::operator=(const Circle& other)
{
	this->_center = other._center;
	this->_radius = other._radius;
	return *this;
}

Circle::~Circle()
{
	this->_center.~Point2D();
	cout << "An object of class Circle has been removed." << endl;
}

void Circle::display()
{
	cout << "Center: ";
	this->_center.display();
	cout << "R = " << this->_radius << endl;

}




