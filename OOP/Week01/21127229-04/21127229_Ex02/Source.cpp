#include "Header.h"
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

void Point::input()
{
	cout << "X: ";
	cin >> this->_x;
	cout << "Y: ";
	cin >> this->_y;
}

void Point::output()
{
	stringstream builder;
	builder << "(" << this->_x << "," << this->_y << ")" << endl;
	cout << builder.str();
}

/// <summary>
/// Distance to Point value
/// </summary>
/// <param name="value"></param>
/// <returns>Distance from this point to value point</returns>
double Point::distanceTo(Point value)
{
	double distance;
	distance = sqrt((this->_x - value._x) * (this->_x - value._x) + (this->_y - value._y) * (this->_y - value._y));
	return distance;
}

double Point::distanceToOy()
{
	return this->_x;
}

double Point::distanceToOx()
{
	return this->_y;
}

void Triangle::input()
{
	Point a, b, c;
	cout << "Point A: " << endl;
	a.input();
	this->_pointA = a;

	cout << "Point B: " << endl;
	b.input();
	this->_pointB = b;

	cout << "Point C: " << endl;
	c.input();
	this->_pointC = c;
}

void Triangle::output()
{
	cout << "Triangle: ";
	this->_pointA.output();
	cout << " ";
	this->_pointB.output();
	cout << " ";
	this->_pointC.output();
	cout << endl;
}

/// <summary>
/// Check valid triangle
/// </summary>
/// <returns>1 if triangle is valid and vice versa</returns>
bool Triangle::isValidTriangle()
{
	double ab = this->_pointA.distanceTo(this->_pointB);
	double bc = this->_pointB.distanceTo(this->_pointC);
	double ac = this->_pointA.distanceTo(this->_pointC);

	if ((ab + bc > ac) && (ab + ac > bc) && (ac + bc > ab))
		return 1;
	return 0;
}

/// <summary>
/// Classify triangle
/// </summary>
/// <returns>a string is the type of triangle</returns>
string Triangle::typeOfTriangle()
{
	double ab = this->_pointA.distanceTo(this->_pointB);
	double bc = this->_pointB.distanceTo(this->_pointC);
	double ac = this->_pointA.distanceTo(this->_pointC);

	string result;

	if (ab == bc && bc == ac)
		result = "Equilateral triangle.\n";
	else if (ab == bc || bc == ac || ab == ac)
		result = "Isosceles triangle.\n";
	else if ((ab * ab + ac * ac == bc * bc) || (ac * ac + bc * bc == ab * ab) || (ab * ab + bc * bc == ac * ac))
		result = "Right-angled triangle.\n";
	else
		result = "Scalene triangle.\n";
	return result;
}

double Triangle::getPerimeter()
{
	double ab = this->_pointA.distanceTo(this->_pointB);
	double bc = this->_pointB.distanceTo(this->_pointC);
	double ac = this->_pointA.distanceTo(this->_pointC);

	double p = ab + bc + ac;
	return p;
}

double Triangle::getArea()
{
	double ab = this->_pointA.distanceTo(this->_pointB);
	double bc = this->_pointB.distanceTo(this->_pointC);
	double ac = this->_pointA.distanceTo(this->_pointC);
	double p = (ab + ac + bc) / 2;

	double area = sqrt(p * (p - ab) * (p - bc) * (p - ac));
	return area;
}

Point Triangle::getCenterG()
{
	Point G;
	double x = (this->_pointA.getX() + this->_pointB.getX() + this->_pointC.getX()) / 3;
	double y = (this->_pointA.getY() + this->_pointB.getY() + this->_pointC.getY()) / 3;
	G.setX(x);
	G.setY(y);
	return G;
}
