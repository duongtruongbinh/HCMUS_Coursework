#pragma once
#include "Triangle.h"
#include "Point2D.h"
#include <sstream>
#include <iostream>
using namespace std;



Triangle::Triangle()
{
	this->_pointA = Point2D(0.0, 0.0);
	this->_pointB = Point2D(0.0, 1.0);
	this->_pointA = Point2D(1.0, 0.0);
}

Triangle::Triangle(Point2D pointA)
{
	Point2D pointB = (2.0, 7.0);
	Point2D pointC = (-9.0, 3.0);
	if (isValidTriangle(pointA, pointB, pointC) == false)
	{
		pointA = Point2D(0.0, 0.0);
		pointB = Point2D(0.0, 1.0);
		pointC = Point2D(1.0, 0.0);
	}
	this->_pointA = pointA;
	this->_pointB = pointB;
	this->_pointC = pointC;
}

Triangle::Triangle(Point2D pointA,Point2D pointB)
{
	Point2D pointC = (9.0, 2.0);
	if (isValidTriangle(pointA, pointB, pointC) == false)
	{
		pointA = Point2D(0.0, 0.0);
		pointB = Point2D(0.0, 1.0);
		pointC = Point2D(1.0, 0.0);
	}
	this->_pointA = pointA;
	this->_pointB = pointB;
	this->_pointC = pointC;
}

Triangle::Triangle(Point2D pointA, Point2D pointB, Point2D pointC)
{	
	if (isValidTriangle(pointA, pointB, pointC) == false)
	{
		pointA = Point2D(0.0, 0.0);
		pointB = Point2D(0.0, 1.0);
		pointC = Point2D(1.0, 0.0);
	}
	this->_pointA = pointA;
	this->_pointB = pointB;
	this->_pointC = pointC;
}

Triangle::Triangle(const Triangle& other)
{
	this->_pointA = other._pointA;
	this->_pointB = other._pointB;
	this->_pointC = other._pointC;
}

Triangle& Triangle::operator=(const Triangle& other)
{
	this->_pointA = other._pointA;
	this->_pointB = other._pointB;
	this->_pointC = other._pointC;
	return *this;
}

Triangle::~Triangle()
{
	this->_pointA.~Point2D();
	this->_pointB.~Point2D();
	this->_pointC.~Point2D();
	cout << "An object of class Triangle has been removed." << endl<<endl;
}


bool Triangle::isValidTriangle(Point2D pointA, Point2D pointB, Point2D pointC)
{
	double ab = _pointA.distanceTo(pointB);
	double ac = _pointA.distanceTo(pointC);
	double bc = _pointB.distanceTo(pointC);

	if ((ab + bc > ac) && (ab + ac > bc) && (ac + bc > ab))
		return 1;
	return 0;
}

void Triangle::display()
{
	this->_pointA.display();
	this->_pointB.display();
	this->_pointC.display();
	cout << endl;
}

